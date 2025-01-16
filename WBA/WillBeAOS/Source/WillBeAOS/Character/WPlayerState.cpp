#include "Character/WPlayerState.h"
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
}
void AWPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ThisClass, TeamID);
}