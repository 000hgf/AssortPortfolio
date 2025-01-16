#include "WMinionsCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "../Character/CombatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "WDelegateDefine.h"
#include "Components/PrimitiveComponent.h"
#include "WMinionsAIController.h"
#include "BrainComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/ProgressBar.h"
#include "HealthBar.h"
#include "../Game/WGameState.h"


AWMinionsCharacterBase::AWMinionsCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	CombatComponent->SetCombatEnable(false);
	CombatComponent->SetCollisionMesh(GetMesh());

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"));
	WidgetComponent->SetupAttachment(GetMesh());
	WidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 200.f));
}

void AWMinionsCharacterBase::NM_Minion_Attack_Implementation()
{
	PlayAnimMontage(MinionAttackMontage);
}

void AWMinionsCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	CombatComponent->DelegateDead.BindUObject(this, &ThisClass::NM_BeingDead);
	//HandleApplyPointDamage 멀티델리게이트 바인딩
	CombatComponent->DelegatePointDamage.AddUObject(this, &ThisClass::HandleApplyPointDamage);
}

void AWMinionsCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float HP = CombatComponent->Health;
	float MAXHP = CombatComponent->Max_Health;

	SetHpPercentage(HP, MAXHP);

	// 게임이 끝나면 로직 끊기
	AWGameState* WGS = Cast<AWGameState>(GetWorld()->GetGameState());
	if (WGS && WGS->CurrentGameState==E_GamePlay::GameEnded)
	{
		AWMinionsAIController* MinionController = Cast<AWMinionsAIController>(GetController());
		if(MinionController)
			MinionController->GetBrainComponent()->StopLogic(TEXT("None"));
	}
}

void AWMinionsCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AWMinionsCharacterBase::NM_BeingDead_Implementation()
{
	if (HasAuthority())
	{
		// AI가 죽으면 BT 연결 끊기
		AWMinionsAIController* MinionController = Cast<AWMinionsAIController>(GetController());
		MinionController->GetBrainComponent()->StopLogic(TEXT("None"));
	}

	//콜리전 없애기
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	// 죽는 애니메이션 실행
	PlayAnimMontage(DeadAnimMontage);
}

void AWMinionsCharacterBase::SetHpPercentage(float Health, float MaxHealth)
{
	auto Widget = Cast<UHealthBar>(WidgetComponent->GetWidget());

	if (Widget != nullptr)
	{
		if (MaxHealth != 0)
			Widget->HealthBar->SetPercent(Health / MaxHealth);
	}
}


void AWMinionsCharacterBase::HandleApplyPointDamage(FHitResult LastHit)
{
	if (HasAuthority())
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
}

float AWMinionsCharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	float TakeDamage = DamageAmount;
	CombatComponent->HandleTakeDamage(TakeDamage);
	//auto Message = FString::Printf(TEXT("%f points of Damage/ %s /Instigator: %s"), TakeDamage, *DamageCauser->GetName(), *EventInstigator->GetPawn()->GetName());
	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	SetHpPercentage((CombatComponent->Health), (CombatComponent->Max_Health));

	return DamageAmount;
}
