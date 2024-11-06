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

	
}


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

