// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS( Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WILLBEAOS_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Combat")
	int32 GetAttackCount();
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SetAttackCount(int32 Val);
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void ResetCombo();
	UFUNCTION(BlueprintCallable, Category = "Combat")
	bool IsCombatEnable();
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SetCombatEnable(bool Val);

protected:
	virtual void BeginPlay() override;

	//공격을 하고있는지 여부
	UPROPERTY(BluePrintReadOnly,Category = "Combat")
	bool CombatEnable = false;

	//콤보에 쓰일 int 인덱스
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	int32 AttackCount = 0;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UCombatComponent();
};
