#pragma once

#include "CoreMinimal.h"
#include "WEnumFile.h"
#include "GameFramework/PlayerState.h"
#include "WPlayerState.generated.h"

UCLASS()
class WILLBEAOS_API AWPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
    AWPlayerState();
    // Attack power
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    int32 CPower;
    // Critical hit chance
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    int32 CCriticalHitChance;
    // Additional health
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    int32 CAdditionalHealth;
    // Defense power
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    int32 CDefense;
    // Movement speed
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    float CSpeed;
    // Cooldown reduction
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    float CCooldownReduction;
    //Exp
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    int32 CCurrentExp;
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    int32 CExperience;
    // Level
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    int32 CLevel;
    UPROPERTY(BlueprintReadWrite, Category = "Stats")
    int32 CAbLevel;
    // Gold
    UPROPERTY(BlueprintReadWrite, Category = "Gold")
    int32 CGold;
	
public:
	UPROPERTY(BlueprintReadWrite,Replicated, Category = "Teams")
	E_TeamID TeamID;
	
	void SetTeamID(E_TeamID NewTeamID){TeamID = NewTeamID;}
};
