#include "WGameState.h"
#include "../Gimmick/Nexus.h"
#include "../Gimmick/Tower.h"
#include "../Character/WCharacterBase.h"
#include "../Character/WPlayerController.h"
#include "Kismet/GameplayStatics.h"

void AWGameState::BeginPlay()
{
    Super::BeginPlay();
    if (GEngine != nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Game State BeginPlay called"));
    }

    Nexus = GetNexus();
    if (Nexus!=nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Found Nexus"));
    }

    GetTower();
    if (TowerArray.Num() > 0)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Found Towers"));
    }
}

ANexus* AWGameState::GetNexus()
{
    ANexus* GameNexus;
    AActor* GetNexus = UGameplayStatics::GetActorOfClass(GetWorld(), ANexus::StaticClass());
    if (GetNexus)
    {
        GameNexus = Cast<ANexus>(GetNexus);
        return GameNexus;

    }
    return nullptr;
}

float AWGameState::GetNexusHP()
{
    if (Nexus != nullptr)
    {
        return Nexus->GetNexusHPPercent();
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
            ATower* Tower = Cast<ATower>(Actor);
            if (Tower)
            {
                TowerArray.Add(Tower);
            }
        }
    }
}

int32 AWGameState::GetTowerNum()
{
    return TowerArray.Num();
}

void AWGameState::HandleNexusDestroyed()
{
    IsGameEnd = true;

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Nexus Destroyed!"));
    }

    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        AWPlayerController* PC = Cast<AWPlayerController>(It->Get());
        if (PC)
        {
            PC->GameHasEnded(nullptr, true);
        }
    }
}

void AWGameState::HandlePlayIsDead()
{
    
}

