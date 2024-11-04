#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WCharacterBase.generated.h"

struct FInputActionValue;
class UInputAction;

UCLASS()
class WILLBEAOS_API AWCharacterBase : public ACharacter
{

	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"));
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"));
	class UCameraComponent* FollowCamera;

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

	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
	void Behavior(const FInputActionValue& Value);


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
