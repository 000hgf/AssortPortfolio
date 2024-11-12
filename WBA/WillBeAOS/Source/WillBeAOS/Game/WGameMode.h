#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "WGameMode.generated.h"

UCLASS()
class WILLBEAOS_API AWGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	virtual void StartPlay();
};
