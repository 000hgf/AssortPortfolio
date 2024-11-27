#include "WPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "WCharacterBase.h"
#include "WCharacterHUD.h"

void AWPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!PlayerHUD && UserWidgetClass)
	{
		PlayerHUD = CreateWidget<UWCharacterHUD>(this, UserWidgetClass);
		if (PlayerHUD)
		{
			PlayerHUD->AddToViewport();

			// Possessed 캐릭터에 대한 초기화 작업 수행
			if (APawn* PossessedPawn = GetPawn())
			{
				AWC = Cast<AWCharacterBase>(PossessedPawn);
				if (AWC)
				{
					PlayerHUD->UpdateCharacter(AWC);
				}
			}
		}
	}
}

void AWPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	if(PlayerHUD)
		PlayerHUD->RemoveFromViewport();

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
	//HUD숨기기
	if (PlayerHUD)
	{
		PlayerHUD->RemoveFromViewport();
	}

	//리스폰 위젯 생성
	RespawnScreen = CreateWidget(this, RespawnScreenClass);
	if (RespawnScreen != nullptr)
	{
		RespawnScreen->AddToViewport();
	}
	//리스폰 타임 맞추기
	CurrentRespawnTime = RespawnTime;
	//타이머 실행
	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &ThisClass::UpdateRespawnWidget, 1.f, true);
}
//타이머 함수
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

void AWPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

//빙의시 hud의 캐릭터 업데이트
void AWPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	//HUD 다시 생성
	if (PlayerHUD)
	{
		PlayerHUD->AddToViewport();
	}
	if (APawn* PossessedPawn = InPawn)
	{
		AWC = Cast<AWCharacterBase>(PossessedPawn);
		if (AWC && PlayerHUD)
		{
			PlayerHUD->UpdateCharacter(AWC);
		}
	}
}
