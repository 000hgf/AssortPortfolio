#include "WGameMode.h"
#include "../Character/WPlayerController.h"
void AWGameMode::StartPlay()
{
	Super::StartPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Mode StartPlay called"));
	
}