#include "WGameState.h"
#include "WGameInstance.h"
#include "WGameMode.h"
#include "WStructure.h"
#include "../Gimmick/Nexus.h"
#include "../Gimmick/Tower.h"
#include "../Character/WPlayerController.h"
#include "Character/WPlayerState.h"
#include "Kismet/GameplayStatics.h"

class UWGameInstance;

void AWGameState::BeginPlay()
{
    Super::BeginPlay();

    WGameMode = Cast<AWGameMode>(GetWorld()->GetAuthGameMode());
    if (WGameMode == nullptr)
    {
        GetWorld()->GetTimerManager().SetTimer(GetGMHandle, this, &AWGameState::UpdateGMTimer, 0.3f, true);
    }
    else
    {
        SetGamePlay(E_GamePlay::GameInit);
    }

    GetTower();
}

void AWGameState::UpdateGMTimer()
{
    WGameMode = Cast<AWGameMode>(GetWorld()->GetAuthGameMode());
    if (WGameMode != nullptr)
    {
        GetWorldTimerManager().ClearTimer(GetGMHandle);
    }
}

void AWGameState::SetGamePlay(E_GamePlay NewState)
{
    if (CurrentGameState == NewState) {return;}
    
    CurrentGameState = NewState;
    UE_LOG(LogTemp, Log, TEXT("GameRunning %s"),*UEnum::GetValueAsString(CurrentGameState));

    GamePlayStateChanged(CurrentGameState);
}

void AWGameState::GamePlayStateChanged(E_GamePlay NewState)
{
    switch (NewState)
    {
    case E_GamePlay::GameInit:
        UE_LOG(LogTemp, Log, TEXT("Game is initializing..."));
        GetPlayerNameFromInstance();
        break;

    case E_GamePlay::PlayerReady://플레이어 컨트롤러 정보를 다 받아와서
        UE_LOG(LogTemp, Log, TEXT("All Players are ready! Updating PlayerControllers..."));
        SpawnPlayer();
        break;

    case E_GamePlay::ReadyCountdown:
        UE_LOG(LogTemp, Log, TEXT("Countdown before game starts!"));
        break;

    case E_GamePlay::Gameplaying:
        //미니언 스폰
            UE_LOG(LogTemp, Log, TEXT("Game has started!"));
        break;

    case E_GamePlay::GameEnded://넥서스 파괴 후
        UE_LOG(LogTemp, Log, TEXT("Game has ended!"));
        break;
    }
}

//-----------------------------------------------------------
//인스턴스에서 플레이어스테이트 맵 가져오기
//-----------------------------------------------------------
void AWGameState::GetPlayerNameFromInstance()
{
        UWGameInstance* WGI = Cast<UWGameInstance>(GetGameInstance());
        if (WGI)
        {
            TMap<FString, FPlayerValue> MatchedMap = WGI->GetMatchTeam();
            for (auto& It : MatchedMap)
            {
                FString PlayerName = It.Key;
                int32 TeamID = It.Value.TeamValue;
                if (!PlayerName.IsEmpty())
                {
                    MatchedPlayers.Add(PlayerName, FPlayerValue(TeamID, false, It.Value.WPawnClass));
                    UE_LOG(LogTemp, Log, TEXT("🔹 불러온 PlayerValue: %s, TeamID: %d"), *PlayerName, TeamID);
                }
                else UE_LOG(LogTemp, Warning, TEXT("PlayerName is Empty"));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Instance is nullptr"));
        }
}

void AWGameState::CheckPlayerIsReady()
{
    if (IsAllPlayerIsReady())
    {
        
        SetGamePlay(E_GamePlay::PlayerReady);
    }
}

bool AWGameState::IsAllPlayerIsReady()
{
    TArray<AWPlayerState*> AllPlayerStates;

    int32 NumPlayers = 0;
    
    for (auto& It : PlayerControllers)
    {
        if (AWPlayerState* PS = Cast<AWPlayerState>(It->PlayerState))
        {
            AllPlayerStates.Add(PS);
            UE_LOG(LogTemp, Log, TEXT("GameState PlayerStateAdd %s"), *PS->GetPlayerName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("PlayerState not found or cast failed."));
        }
    }
    
    for (auto PS : AllPlayerStates)
    {
        for (auto It : MatchedPlayers)
        {
            UE_LOG(LogTemp, Log, TEXT("PlayerState %s %d %s"), *It.Key, It.Value.TeamValue, *It.Value.WPawnClass->GetName());
            if (PS)// 특정 이름 패턴을 가진 경우만 처리
            {
                if (PS->GetPlayerName() == It.Key)
                {
                    SetPlayerState(PS,It.Value);
                    NumPlayers++;
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("PlayerState is not same with matchname."));
                }
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("PlayerState is empty."));
            }
        }
    }

    if (NumPlayers == MatchedPlayers.Num())
    {
        return true;
    }
    return false;
}

void AWGameState::SetPlayerState(AWPlayerState* WPlayerState,FPlayerValue WPlayerValue)
{
    WPlayerState->TeamID = static_cast<E_TeamID>(WPlayerValue.TeamValue);
    WPlayerState->SelectedPawnClass = WPlayerValue.WPawnClass;
    UE_LOG(LogTemp, Log, TEXT("SetPlayerState %s %d %s"), *WPlayerState->GetPlayerName(), WPlayerValue.TeamValue, *WPlayerValue.WPawnClass->GetName());
}

void AWGameState::SpawnPlayer()
{
    for (auto It : PlayerControllers)
    {
        WGameMode->RespawnPlayer(nullptr,It);
    }
}

void AWGameState::RemovePlayer(AWPlayerController* WPlayerController)
{
    if (WPlayerController)
    {
        PlayerControllers.Remove(WPlayerController);
        UE_LOG(LogTemp,Warning,TEXT("Player Removed"));
    }
}

void AWGameState::StartCountdown_Implementation(int32 InitialTime)
{
    CountdownTime = InitialTime;
    
    CurrentGameState = E_GamePlay::ReadyCountdown;
    
    GetWorldTimerManager().SetTimer(CountdownHandle, this, &AWGameState::UpdateCountdown, 1.f, true);
}

void AWGameState::UpdateCountdown()
{
    if (--CountdownTime <= 0)
    {
        GetWorldTimerManager().ClearTimer(CountdownHandle);
        CurrentGameState = E_GamePlay::Gameplaying;

        for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        {
            if (AWPlayerController* PC = Cast<AWPlayerController>(It->Get()))
            {
                PC->OnGameStateChanged(CurrentGameState);
            }
        }
        return;
    }
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("timer"));
}

void AWGameState::AddTowerArray(AAOSActor* SpawnedActor)
{
    ATower* WTower = Cast<ATower>(SpawnedActor);
    if (WTower)
    {
        if (WTower->TeamID == E_TeamID::Red)
        {
            RedTowerArray.Add(WTower);
        }
        else if (WTower->TeamID == E_TeamID::Blue)
        {
            BlueTowerArray.Add(WTower);
        }
    }
    else if (ANexus* WNexus = Cast<ANexus>(SpawnedActor))
    {
        if (WNexus->TeamID == E_TeamID::Red)
        {
            RedNexus = WNexus;
        }
        else if (WNexus->TeamID == E_TeamID::Blue)
        {
            BlueNexus = WNexus;
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Tower %s not found"), *SpawnedActor->GetName());
    }
}


float AWGameState::GetBlueNexusHP()
{
    if (BlueNexus != nullptr)   
    {
        return BlueNexus->GetNexusHPPercent();
        
    } return 0;
}

float AWGameState::GetRedNexusHP()
{
    if (RedNexus != nullptr)   
    {
        return RedNexus->GetNexusHPPercent();
        
    } return 0;
}

void AWGameState::GetTower()
{
    TArray<AActor*> GetTowers = {};
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(),GetTowers);
    if (GetTowers.Num() > 0)
    {
        for (AActor* Actor : GetTowers)
        {
            if (ATower* Tower = Cast<ATower>(Actor))
            {
                if (Tower->TeamID == E_TeamID::Red)
                {
                    RedTowerArray.Add(Tower);
                }
                else if (Tower->TeamID == E_TeamID::Blue)
                {
                    BlueTowerArray.Add(Tower);
                }
                else
                {
                    UE_LOG(LogTemp,Log,TEXT("Tower is not Found"));
                }
            }
        }
    }
}

int32 AWGameState::GetBlueTowerNum()
{
    return BlueTowerArray.Num();
}

int32 AWGameState::GetRedTowerNum()
{
    return RedTowerArray.Num();
}

void AWGameState::RemoveTower(ATower* WTower)
{
    if (WTower->TeamID == E_TeamID::Red)
    {
        RedTowerArray.Remove(WTower);
    }
    else if (WTower->TeamID == E_TeamID::Blue)
    {
        BlueTowerArray.Remove(WTower);
    }
    else
    {
        UE_LOG(LogTemp,Warning,TEXT("Tower is not Found or Netural"));
    }
}
