#include "WPlayerController.h"
#include "Blueprint/UserWidget.h"

void AWPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
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
	RespawnScreen = CreateWidget(this, RespawnScreenClass);
	if (RespawnScreen != nullptr)
	{
		RespawnScreen->AddToViewport();
	}

	CurrentRespawnTime = RespawnTime;

	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &ThisClass::UpdateRespawnWidget, 1.f, true);
}

void AWPlayerController::UpdateRespawnWidget()
{
	if (CurrentRespawnTime > 0)
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
		RespawnScreen->RemoveFromViewport();
	}
}

void AWPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AWPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
