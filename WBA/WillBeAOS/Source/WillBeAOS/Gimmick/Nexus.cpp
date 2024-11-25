#include "Nexus.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "../Character/CombatComponent.h"
#include "../Game/WGameState.h"

ANexus::ANexus()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRootComponent);

	BoxCollisionComponet = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollisionComponet->SetupAttachment(DefaultSceneRootComponent);

	NexusMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NexusMesh"));
	NexusMeshComponent->SetupAttachment(DefaultSceneRootComponent);

	CombatComp = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
}

float ANexus::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	float TakeDamage = DamageAmount;
	if (CombatComp != nullptr)
	{
		CombatComp->HandleTakeDamage(TakeDamage);

		if ((CombatComp->GetIsDead()))
		{
			DefaultSceneRootComponent->SetVisibility(false, true);
			AWGameState* WGameState = GetWorld()->GetGameState<AWGameState>();
			if (WGameState!=nullptr)
			{
				WGameState->HandleNexusDestroyed();
			}
			Destroy();
		}
	}
	/*auto Message = FString::Printf(TEXT("%f points of Damage/ %s /Instigator: %s"),
	TakeDamage, *DamageCauser->GetName(), *EventInstigator->GetPawn()->GetName());

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);*/

	return DamageAmount;
}

float ANexus::GetNexusHPPercent()
{
	return CombatComp->Health/CombatComp->Max_Health;
}

void ANexus::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANexus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

