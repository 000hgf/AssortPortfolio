#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Nexus.generated.h"

UCLASS()
class WILLBEAOS_API ANexus : public AActor
{
	GENERATED_BODY()
	
public:	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* DefaultSceneRootComponent;
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollisionComponet;
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* NexusMeshComponent;
	UPROPERTY(VisibleAnywhere)
	class UCombatComponent* CombatComp;

public:	
	virtual void Tick(float DeltaTime) override;
	
	ANexus();

};
