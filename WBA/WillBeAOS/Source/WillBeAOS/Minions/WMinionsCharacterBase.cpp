#include "WMinionsCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AWMinionsCharacterBase::AWMinionsCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWMinionsCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWMinionsCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWMinionsCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

