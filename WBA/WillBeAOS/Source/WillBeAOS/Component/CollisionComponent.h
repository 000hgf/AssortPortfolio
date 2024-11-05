//#pragma once
//
//#include "CoreMinimal.h"
//#include "Components/ActorComponent.h"
//#include "CollisionComponent.generated.h"
//
//
//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
//class WILLBEAOS_API UCollisionComponent : public UActorComponent
//{
//	GENERATED_BODY()
//
//public:
//	//矫累 家南
//	UPROPERTY(VisibleDefaultsOnly)
//	FName StartSocket;
//	//场 家南
//	UPROPERTY(VisibleDefaultsOnly)
//	FName EndSocket;
//
//	//妮府傈 劝己拳 咯何
//	UPROPERTY(VisibleDefaultsOnly)
//	bool IsCollisionEnabled= false;
//
//	UPROPERTY(VisibleDefaultsOnly)
//	void SetCollisionMesh(UPrimitiveComponent* CollisionMeshComponent);
//	
//	UPROPERTY(VisibleDefaultsOnly)
//	void CollisionTrace();
//
//protected:
//	virtual void BeginPlay() override;
//
//public:	
//	UCollisionComponent();
//
//	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
//
//};