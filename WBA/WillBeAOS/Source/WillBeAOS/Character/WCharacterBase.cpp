#include "WCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/ProgressBar.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CombatComponent.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "WPlayerController.h"
#include "WCharacterHUD.h"


AWCharacterBase::AWCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationRoll = false;
	this->bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraBoom->bUsePawnControlRotation = true;

	CombatComp = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	CombatComp->SetCombatEnable(false);

}


void AWCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	//BeingDead 델리게이트 바인딩
	CombatComp->DelegateDead.BindUObject(this, &ThisClass::BeingDead);
	//HandleApplyPointDamage 멀티델리게이트 바인딩
	CombatComp->DelegatePointDamage.AddUObject(this, &ThisClass::HandleApplyPointDamage);
}
		//Char->PlayAnimMontage(HitAnimMontage); 

void AWCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//float HP = CombatComp->Health;
	//float MAXHP = CombatComp->Max_Health;

	//SetHpPercentage(HP, MAXHP);
}

void AWCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	// IMC 세팅
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(IMC_Asset, 0);
		}
	}

	// InputAction 붙이기
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AWCharacterBase::Look);
		EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AWCharacterBase::Move);
		EnhancedInputComponent->BindAction(IA_Behavior, ETriggerEvent::Started, this, &AWCharacterBase::Behavior);
	}
}

float AWCharacterBase::GetHpPercentage()	// HP 게이지 업데이트
{
	return (CombatComp->Health / CombatComp->Max_Health);
}

void AWCharacterBase::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AWCharacterBase::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRatator(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRatator).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRatator).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AWCharacterBase::Behavior(const FInputActionValue& Value)
{
	CombatComp->SetCollisionMesh(GetMesh());
	if (CombatComp != nullptr)
	{
		//공격중이 아닐시
		if ((CombatComp->IsCombatEnable() == false))
		{
			//공격중 활성화
			CombatComp->SetCombatEnable(true);
			DSkillLCooldown.ExecuteIfBound();
			//콤보 로직
			if ((CombatComp->GetAttackCount()) < AttackMontages.Num())
			{
				ACharacter::PlayAnimMontage(AttackMontages[(CombatComp->GetAttackCount())]);
				CombatComp->AddAttackCount(1);
				if (CombatComp->GetAttackCount() >= AttackMontages.Num())
				{
					CombatComp->ResetCombo();
				}
			}
		}
	}
}

void AWCharacterBase::BeingDead()
{
	// 리스폰 위젯 출력
	AWPlayerController* PC = Cast<AWPlayerController>(GetController());
	if (PC)
	{
		PC->ShowRespawnWidget(); 
	}

	////죽음 메세지 출력
	auto Message = FString::Printf(TEXT("Dead"));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
	//무브먼트, 콜리전 없애고 몽타주 출력
	ACharacter::GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	ACharacter::GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ACharacter::GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	ACharacter::PlayAnimMontage(DeadAnimMontage);
}

//포인트 데미지 주는 함수
void AWCharacterBase::HandleApplyPointDamage(FHitResult LastHit)
{
	UGameplayStatics::ApplyPointDamage(
		LastHit.GetActor(),
		CharacterDamage,
		GetOwner()->GetActorForwardVector(),
		LastHit,
		GetInstigatorController(),
		this,
		UDamageType::StaticClass()
	);
}


float AWCharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	float TakeDamage = DamageAmount;
	CombatComp->HandleTakeDamage(TakeDamage);
	//auto Message = FString::Printf(TEXT("%f points of Damage/ %s /Instigator: %s"), TakeDamage, *DamageCauser->GetName(), *EventInstigator->GetPawn()->GetName());
	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	return DamageAmount;
}


