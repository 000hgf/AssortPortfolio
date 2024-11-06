// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WPlayerController.generated.h"

UCLASS()
class WILLBEAOS_API AWPlayerController : public APlayerController
{
	GENERATED_BODY()

	//�̱� ����
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;
	//�й� ����
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;
	//���� ����
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> DeathScreenClass;

	//�������� �ʿ���
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5;

	FTimerHandle RestartTimer;

public:

	//������ �Լ�(PlayerController->GameHasEnded())
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
