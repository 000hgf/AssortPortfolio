#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WDelegateDefine.h"
#include "WMinionsCharacterBase.generated.h"

class UAnimMontage;
class UCombatComponent;
class UWidgetComponent;
class UProgressBar;

UCLASS()
class WILLBEAOS_API AWMinionsCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCombatComponent* CombatComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UWidgetComponent* WidgetComponent;
	
public:
	AWMinionsCharacterBase();
	
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	TArray<UAnimMontage*> AttackMontages = {};

	UPROPERTY(BlueprintReadWrite, Category = Dead)
	UAnimMontage* DeadAnimMontage;

	FDelegateSignature DelegateDead;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void HandleApplyPointDamage(FHitResult LastHit);//포인트 데미지를 줄시 델리게이트로 호출될 함수
	UFUNCTION(BlueprintCallable, Category = "Combat")
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	float CharacterDamage;	//데미지

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(NetMulticast, Reliable)
	void SetHpPercentage(float Health, float MaxHealth);
	UFUNCTION(Server, Reliable)
	void S_SetHpPercentage(float Health, float MaxHealth);
	
	//RPC로 서버에서 호출
	
	UFUNCTION(NetMulticast, Reliable)
	void NM_BeingDead();	// Multicast로 Client들에게 전달
	
	UFUNCTION(NetMulticast,BlueprintCallable, Reliable)
	void NM_Minion_Attack();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* MinionAttackMontage;
};
