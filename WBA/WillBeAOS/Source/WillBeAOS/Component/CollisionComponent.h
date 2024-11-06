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
//	//���� ����
//	UPROPERTY(VisibleDefaultsOnly)
//	FName StartSocket;
//	//�� ����
//	UPROPERTY(VisibleDefaultsOnly)
//	FName EndSocket;
//
//	//�ݸ��� Ȱ��ȭ ����
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