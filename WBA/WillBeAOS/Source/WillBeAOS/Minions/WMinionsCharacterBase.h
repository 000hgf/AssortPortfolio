#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WMinionsCharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;

UCLASS()
class WILLBEAOS_API AWMinionsCharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Camera)
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(EditAnywhere, Category = Camera)
	UCameraComponent* CameraComponent;
	
public:
	AWMinionsCharacterBase();

	UPROPERTY(BlueprintReadWrite, Category = HP)
	float MaxHealth = 1000;
	UPROPERTY(BlueprintReadWrite, Category = HP)
	float Health;
	UPROPERTY(BlueprintReadWrite)
	float AttackPoint = 50;

	UPROPERTY(BlueprintReadWrite, Category = Combo)
	TArray<UAnimMontage*> AttackMontages = {};
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	float AttackCount = 0;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
