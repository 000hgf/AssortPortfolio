#include "WPlayerState.h"
#include "Net/UnrealNetwork.h"

AWPlayerState::AWPlayerState()
{
    bReplicates = true;
    // Initialize default values for the player's stats
    CPower = 10;
    CCriticalHitChance = 5; // Percentage
    CAdditionalHealth = 100;
    CDefense = 5;
    CSpeed = 600.0f; // Unreal units per second
    CCooldownReduction = 0.0f; // Percentage
    
    CCurrentExp = 0;
    CExperience = 100;
    
    CLevel = 0;
    CAbLevel = 0;
    CGold = 0;

    CKillCount = 0;
    CDeathCount = 0;
}

void AWPlayerState::AddKillCount()
{
    CKillCount++;
}

void AWPlayerState::AddDeathCount()
{
    CDeathCount++;
}

void AWPlayerState::AddExperience_Implementation(int32 Amount)
{
    CCurrentExp += Amount;
    if (CCurrentExp >= CExperience)
    {
        CLevel++;
        CCurrentExp = 0;
    }
}

void AWPlayerState::AddGold_Implementation(int32 Amount)
{
    CGold += Amount;
}

void AWPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ThisClass, TeamID);
    DOREPLIFETIME(ThisClass, CPower);
    DOREPLIFETIME(ThisClass, CDefense);
    DOREPLIFETIME(ThisClass, CCriticalHitChance);
    DOREPLIFETIME(ThisClass, CCurrentExp);
    DOREPLIFETIME(ThisClass, CLevel);
    DOREPLIFETIME(ThisClass, CAbLevel);
    DOREPLIFETIME(ThisClass, CSpeed);
    DOREPLIFETIME(ThisClass, CCooldownReduction);
    DOREPLIFETIME(ThisClass, CExperience);
    DOREPLIFETIME(ThisClass, CGold);
}
