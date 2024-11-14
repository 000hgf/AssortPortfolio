#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

class USceneComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class WILLBEAOS_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	ATower();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultSceneRoot;
	UPROPERTY(EditAnywhere)
	USphereComponent* OverlapTrigger;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* AttackStartPoint;
	
	FVector HitLocation;
	FVector HitNormal;
	FName BoneName;
	FHitResult OutHit;
	// 오버랩된 액터들의 배열 ( 공격 대상들 )
	TArray<AActor*> OverlappingActors = {};

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable)
	virtual void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
