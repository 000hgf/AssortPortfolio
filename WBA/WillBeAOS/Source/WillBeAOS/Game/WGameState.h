#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "WGameState.generated.h"


UCLASS()
class WILLBEAOS_API AWGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay();

	class ANexus* GetNexus();

	void HandleNexusDestroyed();
	void HandlePlayIsDead();
};
