// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WDelegateDefine.h"
#include "CombatComponent.generated.h"

UCLASS( Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WILLBEAOS_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	///콜리전 관련 처리
	//시작 소켓
	UPROPERTY(EditAnywhere, Category = "Collision")
	FName StartSocket;
	//끝 소켓
	UPROPERTY(EditAnywhere, Category = "Collision")
	FName EndSocket;

	//콜리전 활성화 여부
	UPROPERTY(VisibleDefaultsOnly)
	bool IsCollisionEnabled = false;

	//스켈레탈 메쉬의 콜리전 컴포넌트
	UPROPERTY(VisibleDefaultsOnly)
	UPrimitiveComponent* CollisionMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Collision")
	float Radius;
	//오브젝트 타입
	UPROPERTY(EditAnywhere, Category = "Collision")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes = {};

	//프리미티브 컴포넌트 설정
	UFUNCTION()
	void SetCollisionMesh(UPrimitiveComponent* PrimComp);

	//충돌 관련 처리
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void CollisionTrace();//충돌 트레이스 
	UFUNCTION(BlueprintCallable, Category = "Collsion")
	void EnableCollision();//콜리전 활성화
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void DisableCollision();//콜리전 비활성화
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void ClearHitActor();//히트액터 배열 초기화

	// 전투관련 처리
	UFUNCTION(BlueprintCallable, Category = "Combat")
	int32 GetAttackCount();//콤보 횟수
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void AddAttackCount(int32 Val);//콤보 횟수 세팅
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void ResetCombo();//콤보 리셋
	UFUNCTION(BlueprintCallable, Category = "Combat")
	bool IsCombatEnable();//전투중인지 판별
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SetCombatEnable(bool Val);//전투중 활성화

	//체력관련 함수
	UFUNCTION(BlueprintCallable, Category = "Health")
	void HandleTakeDamage(float Damage);//데미지 받음

	FDelegateSignature DelegateDead;//죽을때 사용할 델리게이트
	FMDS1 DelegatePointDamage;//포인트 데미지에 사용할 델리게이트

protected:
	virtual void BeginPlay() override;

public:
	//공격을 하고있는지 여부
	UPROPERTY(BluePrintReadOnly, Category = "Combat")
	bool CombatEnable = false;

	//콤보에 쓰일 int 인덱스
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	int32 AttackCount = 0;

	//충돌된 히트액터 배열
	UPROPERTY(EditAnywhere, Category = "Collision")
	TArray<AActor*> AlreadyHitActors = {};

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	float Health = 50;
	UPROPERTY(EditAnywhere, Category = "Health")
	float Max_Health = 100;
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	bool IsDead;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetIsDead(bool Val);
	UFUNCTION(BlueprintCallable, Category = "Health")
	bool GetIsDead();
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UCombatComponent();
};
