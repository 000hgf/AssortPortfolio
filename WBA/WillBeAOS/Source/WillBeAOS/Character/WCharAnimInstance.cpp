#include "WCharAnimInstance.h"
#include "WCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


void UWCharAnimInstance::NativeInitializeAnimation()
{
	// 캐릭터 레퍼런스 저장
	WCharBase = Cast<AWCharacterBase>(TryGetPawnOwner());
	if (WCharBase != nullptr)
	{
		WCharMovementComponent = WCharBase->GetCharacterMovement();
	}
}

// 애니메이션 업데이트 루프
void UWCharAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{

	if (WCharMovementComponent)
	{
		WCharVelocity = WCharMovementComponent->Velocity;
		WCharSpeed = UKismetMathLibrary::VSizeXY(WCharVelocity);

		WShouldMove = false;
		bool Acceleration = !WCharMovementComponent->GetCurrentAcceleration().Equals(FVector::ZeroVector, 0);
		if (WCharSpeed > 3.f && Acceleration)
		{
			WShouldMove = true;
		}

		float CurveValue = UAnimInstance::GetCurveValue(TEXT("FullBody"));
		if (CurveValue > 0.f)
		{
			FullBody = true;
		}

		WCharInAir = WCharMovementComponent->IsFalling();
	}
}
