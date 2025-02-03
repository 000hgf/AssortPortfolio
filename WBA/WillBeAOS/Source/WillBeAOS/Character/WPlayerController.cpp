#include "WPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "WCharacterBase.h"
#include "WCharacterHUD.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Net/UnrealNetwork.h"

void AWPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);

	if (IsLocalController())
	{
		CreateGamePlayHUD(GetPawn());
	}
}

void AWPlayerController::CreateGamePlayHUD(APawn* PlayerChar)
{
	if (!IsValid(PlayerHUD))
	{
		PlayerHUD = CreateWidget<UWCharacterHUD>(this, UserWidgetClass);

		PlayerHUD->AddToViewport();
		PlayerHUD->UpdateCharacter(Cast<AWCharacterBase>(PlayerChar));
	}
	else
	{
		if (!PlayerHUD->IsInViewport())
		{
			PlayerHUD->AddToViewport();
			PlayerHUD->UpdateCharacter(Cast<AWCharacterBase>(PlayerChar));
		}
	}
}

void AWPlayerController::OnGameStateChanged(E_GamePlay CurrentGameState)
{
	switch (CurrentGameState)
	{
	case E_GamePlay::GameInit:
		DisableInput(this);
		break;
    
	case E_GamePlay::ReadyCountdown:
		DisableInput(this);
		// 카운트다운 UI 표시
		break;
    
	case E_GamePlay::Gameplaying:
		EnableInput(this);
		// HUD 업데이트
		break;
    
	case E_GamePlay::GameEnded:
		GameHasEnded();
		// 결과 화면 표시
		break;
    
	default:
		break;
	}
}


void AWPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	
	if(PlayerHUD)
		PlayerHUD->RemoveFromParent();

	if (bIsWinner)
	{
		SetShowMouseCursor(true);
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		SetShowMouseCursor(true);
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}
}

void AWPlayerController::ShowRespawnWidget()
{
	if (!IsLocalController())
	{
		return;
	}

	FString PossessedPawn = GetPawn()->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, PossessedPawn);
	
	if (PlayerHUD)
	{
		PlayerHUD->RemoveFromParent();
	}

	
	RespawnScreen = CreateWidget(this, RespawnScreenClass);
	if (RespawnScreen != nullptr)
	{
		RespawnScreen->AddToViewport();
	}

	AWGameState* GameState = Cast<AWGameState>(GetWorld()->GetGameState());
	CurrentRespawnTime = GameState->RespawnTime;
	
	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &ThisClass::UpdateRespawnWidget, 1.f, true);
}

void AWPlayerController::UpdateRespawnWidget()
{
	if (!IsLocalController())
	{
		return;
	}
	
	if (CurrentRespawnTime > 1)
	{
		CurrentRespawnTime--;
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHandle);
		HideRespawnWidget();
	}
}

void AWPlayerController::HideRespawnWidget()
{
	if (RespawnScreen != nullptr)
	{
		RespawnScreen->RemoveFromParent();
	}
}

void AWPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}


void AWPlayerController::OnPossess(APawn* InPawn)
{	
	Super::OnPossess(InPawn);

	if (IsLocalController())
	{
		CreateGamePlayHUD(InPawn);
	}
	/*if (PlayerHUD)
	{
		PlayerHUD->AddToViewport();

		if (InPawn)
		{
			AWC = Cast<AWCharacterBase>(InPawn);
			if (AWC)
			{
				PlayerHUD->UpdateCharacter(AWC);
			}
		}
	}*/
}