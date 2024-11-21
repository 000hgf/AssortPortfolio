#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WPlayerController.generated.h"

UCLASS()
class WILLBEAOS_API AWPlayerController : public APlayerController
{
	GENERATED_BODY()

	//ÀÌ±è À§Á¬
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> WinScreenClass;
	//ÆÐ¹è À§Á¬
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> LoseScreenClass;
	//Á×À½ À§Á¬
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> DeathScreenClass;
	// ¸®½ºÆù À§Á¬
	UPROPERTY(EditAnywhere, Category = Widget)
	TSubclassOf<UUserWidget> RespawnScreenClass;
	UUserWidget* RespawnScreen;

public:
	//¸®½ºÆù½Ã ÇÊ¿äÇÑ
	UPROPERTY(BlueprintReadWrite)
	int RespawnTime = 5;
	UPROPERTY(BlueprintReadWrite)
	int CurrentRespawnTime;

	FTimerHandle RestartTimer;
	FTimerHandle RespawnTimerHandle;

public:

	//¸®½ºÆù ÇÔ¼ö(PlayerController->GameHasEnded())
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
	void ShowRespawnWidget();
	void UpdateRespawnWidget();
	void HideRespawnWidget();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
