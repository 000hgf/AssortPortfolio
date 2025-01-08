#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WPlayerController.generated.h"

class UUserWidget;

UCLASS()
class WILLBEAOS_API AWPlayerController : public APlayerController
{
	GENERATED_BODY()

	//이김 위젯
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf< UUserWidget> WinScreenClass;
	//패배 위젯
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf< UUserWidget> LoseScreenClass;
	//죽음 위젯
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf< UUserWidget> DeathScreenClass;
	// 리스폰 위젯
	UPROPERTY(EditAnywhere, Category = Widget)
	TSubclassOf<UUserWidget> RespawnScreenClass;

	// UserWidget 클래스의 타입을 저장하는 변수
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> UserWidgetClass;

	class UWCharacterHUD* PlayerHUD;

	UUserWidget* RespawnScreen;

	class AWCharacterBase* AWC;

public:
	//리스폰시 필요한
	UPROPERTY(BlueprintReadWrite)
	int RespawnTime = 5;
	UPROPERTY(BlueprintReadWrite)
	int CurrentRespawnTime;

	FTimerHandle RestartTimer;
	FTimerHandle RespawnTimerHandle;

public:

	//리스폰 함수(PlayerController->GameHasEnded())
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
	void ShowRespawnWidget();
	void UpdateRespawnWidget();
	void HideRespawnWidget();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnPossess(APawn* InPawn);
};
