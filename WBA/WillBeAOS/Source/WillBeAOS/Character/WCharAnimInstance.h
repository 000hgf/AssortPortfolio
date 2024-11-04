#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WCharAnimInstance.generated.h"

class AWCharacterBase;
class UCharacterMovementComponent;

UCLASS()
class WILLBEAOS_API UWCharAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category=Movement)
	AWCharacterBase* WCharBase;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	UCharacterMovementComponent* WCharMovementComponent;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	FVector WCharVelocity;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float WCharSpeed;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool WShouldMove;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool WCharInAir;
	UPROPERTY(BlueprintReadOnly)
	bool FullBody;

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
