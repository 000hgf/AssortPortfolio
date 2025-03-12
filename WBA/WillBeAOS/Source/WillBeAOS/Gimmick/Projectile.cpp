#include "Gimmick/Projectile.h"


AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 클라이언트 투사체 위치 보간
	if (!HasAuthority())  // 클라이언트에서만 실행
	{
		FVector TargetLocation = GetActorLocation();  // 서버에서 동기화된 위치
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), TargetLocation, DeltaTime, 10.0f));
	}
}

