#include "CombatComponent.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


int32 UCombatComponent::GetAttackCount()
{
	return AttackCount;
}

void UCombatComponent::SetAttackCount(int32 Val)
{
	AttackCount += Val;
}

void UCombatComponent::ResetCombo()
{
	AttackCount = 0;
}

bool UCombatComponent::IsCombatEnable()
{
	if (CombatEnable)
	{
		return true;
	}
	else { return false; }
}

void UCombatComponent::SetCombatEnable(bool Val)
{
	CombatEnable = Val;
}

// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = Max_Health;
}

void UCombatComponent::WTakeDamage(float Damage)
{
	if (Health > 0)
	{
		Health -= Damage;
	}
	else if (Damage > Health)
	{
		Health = 0;
	}
	if (!Health)
	{
		SetIsDead(true);
		DelegateDead.ExecuteIfBound();
	}
}

void UCombatComponent::SetIsDead(bool Val)
{
	IsDead = Val;
}

bool UCombatComponent::GetIsDead()
{
	return IsDead;
}


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

