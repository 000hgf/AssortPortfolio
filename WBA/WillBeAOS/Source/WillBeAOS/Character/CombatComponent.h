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

	//������ �ϰ��ִ��� ����
	UPROPERTY(BluePrintReadOnly,Category = "Combat")
	bool CombatEnable = false;

	//�޺��� ���� int �ε���
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	int32 AttackCount = 0;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UCombatComponent();
};
