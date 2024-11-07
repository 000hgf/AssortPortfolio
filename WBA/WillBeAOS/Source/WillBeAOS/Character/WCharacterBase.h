#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WCharacterBase.generated.h"

struct FInputActionValue;
class UInputAction;
class UAnimMontage;

UCLASS()
class WILLBEAOS_API AWCharacterBase : public ACharacter
{

	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"));
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"));
	class UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"));
	class UCombatComponent* CombatComp;

public:
	AWCharacterBase();

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* IMC_Asset;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_Look;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_Jump;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_Behavior;

	//Á×À»¶§ ¾²ÀÏ ¸ùÅ¸ÁÖ
	UPROPERTY(BlueprintReadWrite, Category = "Health")
	UAnimMontage* DeadAnimMontage;
	//ÇÇ°Ý½Ã ¾²ÀÏ ¸ùÅ¸ÁÖ
	UPROPERTY(BlueprintReadWrite, Category = "Health")
	UAnimMontage* HitAnimMontage;
	//ÄÞº¸¿¡ ¾²ÀÏ ¾Ö´Ô¸ùÅ¸ÁÖ ¹è¿­
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	TArray<UAnimMontage*> AttackMontages = {};

	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
	void Behavior(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category = Dead)
	void BeingDead();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
