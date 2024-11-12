#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttackTower.generated.h"

UCLASS()
class WILLBEAOS_API AAttackTower : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USphereComponent* AttackRange;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* TowerMesh;
protected:

	float FireRate;

	class AWCharacterBase* CurrentTarget;

	virtual void BeginPlay() override;

	struct FTimerHandle AttackTimerHandle;
public:	
	AAttackTower();

	virtual void Tick(float DeltaTime) override;
	virtual void OnEnemyEnterRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnEnemyLeaveRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Attack();
};
