#include "WMinionsCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "../Character/CombatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "WDelegateDefine.h"
#include "Components/PrimitiveComponent.h"
#include "WMinionsAIController.h"
#include "BrainComponent.h"


AWMinionsCharacterBase::AWMinionsCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	CombatComponent->SetCombatEnable(false);
}

void AWMinionsCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	//CombatComponent->DelegateDead.BindUObject(this, &ThisClass::BeingDead);

	Health = MaxHealth;
}

void AWMinionsCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWMinionsCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AWMinionsCharacterBase::EnemyTakeDamage(float Damage)
{
	if (Health > 0)
	{
		if (Health < Damage)
			Health = 0;
		else
			Health -= Damage;
	}

	if (Health <= 0)
	{
		//DelegateDead.ExecuteIfBound();
		BeingDead();
	}
}

void AWMinionsCharacterBase::BeingDead()
{
	// AI�� ������ BT ���� ����
	AWMinionsAIController* MinionController = Cast<AWMinionsAIController>(GetController());
	MinionController->GetBrainComponent()->StopLogic(TEXT("None"));

	//�ݸ��� ���ֱ�
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	// �״� �ִϸ��̼� ����
	PlayAnimMontage(DeadAnimMontage);
}

