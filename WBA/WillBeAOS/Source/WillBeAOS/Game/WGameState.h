#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "WGameState.generated.h"

class ATower;
class ANexus;

UCLASS()
class WILLBEAOS_API AWGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay();

	float GetNexusHP();

	void GetTower();//필드의 타워객체들을 받아오는 함수
					//추후 피아식별 후 따로 받아올 예정
	UFUNCTION(BlueprintCallable, Category = "Tower")
	int32 GetTowerNum();

	UPROPERTY(BlueprintReadOnly, Category = "Tower")
	TArray<ATower*> TowerArray = {};//타워 객체들

	UPROPERTY(BlueprintReadWrite, Category = "State")
	bool IsGameEnd = false;

	void HandleNexusDestroyed();
	void HandlePlayIsDead();

protected:

	ANexus* Nexus;//넥서스
	ANexus* GetNexus();//필드의 넥서스객체들을 받아오는 함수
						//추후 피아식별후 수정
};
