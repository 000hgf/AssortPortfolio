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

			// Possessed ĳ���Ϳ� ���� �ʱ�ȭ �۾� ����
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
	//HUD�����
	if (PlayerHUD)
	{
		PlayerHUD->RemoveFromParent();
	}

	//������ ���� ����
	RespawnScreen = CreateWidget(this, RespawnScreenClass);
	if (RespawnScreen != nullptr)
	{
		RespawnScreen->AddToViewport();
	}
	//������ Ÿ�� ���߱�
	CurrentRespawnTime = RespawnTime;
	//Ÿ�̸� ����
	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &ThisClass::UpdateRespawnWidget, 1.f, true);
}
//Ÿ�̸� �Լ�
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
		RespawnScreen->RemoveFromParent();
	}
}

void AWPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

//���ǽ� hud�� ĳ���� ������Ʈ
void AWPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	//HUD �ٽ� ����
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
