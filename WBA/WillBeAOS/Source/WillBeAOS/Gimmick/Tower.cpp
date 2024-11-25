#include "Tower.h"
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../Character/WCharacterBase.h"
#include "../Character/CombatComponent.h"
#include "../Game/WGameState.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../Character/WCharacterBase.h"
#include "../Minions/WMinionsCharacterBase.h"

ATower::ATower()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	CapsuleCollisionComponet = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollision"));
	CapsuleCollisionComponet->SetupAttachment(GetRootComponent());

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraParticleSystem"));
	NiagaraComponent->SetupAttachment(GetRootComponent());

	OverlapTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapTrigger"));
	OverlapTrigger->SetupAttachment(GetRootComponent());

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(GetRootComponent());

	AttackStartPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AttackStartPoint"));
	AttackStartPoint->SetupAttachment(NiagaraComponent);

	CombatComp = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));

	// 특정 요소의 오버랩 함수 바인드하기 ( OverlapTrigger의 )
	OverlapTrigger->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	OverlapTrigger->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (OverlappingActors.IsValidIndex(0))
	{

		TargetOfActors = OverlappingActors[0];
		NiagaraComponent->SetVectorParameter("Beam End", (TargetOfActors->GetActorLocation()) - AttackStartPoint->GetComponentLocation());
		NiagaraComponent->SetVisibility(true);

		// 라인 트레이스
	/*	UKismetSystemLibrary::LineTraceMulti(
			GetWorld(),
			AttackStartPoint->GetComponentLocation(),
			TargetOfActors->GetActorLocation(),
			TraceChannel,
			false,
			ActorsToIgnore,
			EDrawDebugTrace::ForOneFrame,
			OutHits,
			true
		);*/

		/*AttackStartPoint->K2_LineTraceComponent(
			AttackStartPoint->GetComponentLocation(),
			TargetOfActors->GetActorLocation(),
			true,
			true,
			false,
			HitLocation,
			HitNormal,
			BoneName,
			OutHit
		);*/

		// 2초마다 한번씩 스폰
		Delta += DeltaTime;
		if(Delta >= 2)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			GetWorld()->SpawnActor<AActor>(SpawnActors, AttackStartPoint->GetComponentTransform(), SpawnParams);
			Delta = 0;
		}

		// 나의 고생들...
		//FTimerHandle handle;
		//FActorSpawnParameters SpawnParams;
		//FTimerDelegate TimerCallback;

		//TimerCallback.BindLambda(
		//	[this, SpawnParams]
		//	{
		//		GetWorld()->SpawnActor<AActor>(SpawnActors, AttackStartPoint->GetComponentTransform(), SpawnParams);
		//	});
		//GetWorld()->GetTimerManager().SetTimer(handle, TimerCallback, 3.0f, false);
		////GetWorldTimerManager().SetTimer(handle, &ATower::spawn(), 3.f, false);
	}
}

float ATower::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	float TakeDamage = DamageAmount;
	if (CombatComp != nullptr)
	{
		CombatComp->HandleTakeDamage(TakeDamage);

		if ((CombatComp->GetIsDead()))
		{
			//DefaultSceneRoot->SetVisibility(false, true);
			//AWGameState* WGameState = GetWorld()->GetGameState<AWGameState>();
			//if (WGameState != nullptr)
			//{
			//	WGameState->HandleNexusDestroyed();
			//}
			Destroy();
		}
	}
	/*auto Message = FString::Printf(TEXT("%f points of Damage/ %s /Instigator: %s"),
		TakeDamage, *DamageCauser->GetName(), *EventInstigator->GetPawn()->GetName());

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);*/

	return DamageAmount;
}

void ATower::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AWCharacterBase>(OtherActor) || Cast<AWMinionsCharacterBase>(OtherActor))
	{
		OverlappingActors.AddUnique(OtherActor);
	}
}

void ATower::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	OverlappingActors.Remove(OtherActor);

	// 타깃 배열이 비어있으면 스폰 시간 초기화 및 Niagara 비활성화
	if (OverlappingActors.IsEmpty())
	{
		Delta = 0;
		NiagaraComponent->SetVisibility(false);
	}
}

void ATower::spawn()
{
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<AActor>(SpawnActors, AttackStartPoint->GetComponentTransform(), SpawnParams);
}