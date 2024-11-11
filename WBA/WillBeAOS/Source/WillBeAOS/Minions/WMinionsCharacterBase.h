#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WDelegateDefine.h"
#include "WMinionsCharacterBase.generated.h"

class UAnimMontage;
class UCombatComponent;

UCLASS()
class WILLBEAOS_API AWMinionsCharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UCombatComponent* CombatComponent;
	
public:
	AWMinionsCharacterBase();

	UPROPERTY(BlueprintReadWrite, Category = HP)
	float MaxHealth = 100;
	UPROPERTY(BlueprintReadWrite, Category = HP)
	float Health;
	UPROPERTY(BlueprintReadWrite)
	float AttackPoint = 10;

	UPROPERTY(BlueprintReadWrite, Category = Combo)
	TArray<UAnimMontage*> AttackMontages = {};
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	float AttackCount = 0;

	UPROPERTY(BlueprintReadWrite, Category = Dead)
	UAnimMontage* DeadAnimMontage;

	FDelegateSignature DelegateDead;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void EnemyTakeDamage(float Damage);
	void BeingDead();

};
