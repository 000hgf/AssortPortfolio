#include "AttackTower.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "../Character/WCharacterBase.h"

AAttackTower::AAttackTower()
{
    PrimaryActorTick.bCanEverTick = true;

    // 씬 컴포넌트를 루트로 설정
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    // 타워의 범위를 설정하는 스피어 컴포넌트 생성
    AttackRange = CreateDefaultSubobject<USphereComponent>(TEXT("AttackRange"));
    AttackRange->InitSphereRadius(1000.0f);
    AttackRange->SetupAttachment(RootComponent);

    // 타워의 시각적 요소 설정
    TowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerMesh"));
    TowerMesh->SetupAttachment(RootComponent);

    AttackRange->OnComponentBeginOverlap.AddDynamic(this, &AAttackTower::OnEnemyEnterRange);
    AttackRange->OnComponentEndOverlap.AddDynamic(this, &AAttackTower::OnEnemyLeaveRange);

    FireRate = 2.0f; // 공격 주기 (초 단위)
}

void AAttackTower::BeginPlay()
{
    Super::BeginPlay();
}

void AAttackTower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (CurrentTarget)
    {
        FVector Direction = (CurrentTarget->GetActorLocation() - GetActorLocation()).GetSafeNormal();
        FRotator LookAtRotation = FRotationMatrix::MakeFromX(Direction).Rotator();
        SetActorRotation(LookAtRotation);
    }
}

void AAttackTower::OnEnemyEnterRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AWCharacterBase* Enemy = Cast<AWCharacterBase>(OtherActor);
    if (Enemy && !CurrentTarget)
    {
        CurrentTarget = Enemy;
        GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &AAttackTower::Attack, FireRate, true);
    }
}

void AAttackTower::OnEnemyLeaveRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    AWCharacterBase* Enemy = Cast< AWCharacterBase>(OtherActor);
    if (Enemy && Enemy == CurrentTarget)
    {
        CurrentTarget = nullptr;
        GetWorld()->GetTimerManager().ClearTimer(AttackTimerHandle);
    }
}

void AAttackTower::Attack()
{
    if (CurrentTarget&&(!CurrentTarget->IsDead))
    {
        UGameplayStatics::ApplyDamage(CurrentTarget, 10.0f, GetInstigatorController(), this, UDamageType::StaticClass());
    }
    else
    {
        GetWorld()->GetTimerManager().ClearTimer(AttackTimerHandle);
        CurrentTarget = nullptr;
    }
}
