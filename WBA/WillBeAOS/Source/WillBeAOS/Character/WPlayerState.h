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
    UPROPERTY(Replicated,BlueprintReadWrite, Category = "Stats")
    int32 CPower;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCPower() {return CPower;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCPower(int32 Power) {CPower = Power;}
	
    // Critical hit chance
    UPROPERTY(Replicated,BlueprintReadWrite, Category = "Stats")
    int32 CCriticalHitChance;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCCriticalHitChance() {return CCriticalHitChance;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCCriticalHitChance(int32 Chance) {CCriticalHitChance = Chance;}
	
    // Additional health
    UPROPERTY(Replicated,BlueprintReadWrite, Category = "Stats")
    int32 CAdditionalHealth;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCAdditionalHealth() {return CAdditionalHealth;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCAdditionalHealth(int32 Health) {CAdditionalHealth = Health;}
	
    // Defense power
    UPROPERTY(Replicated,BlueprintReadWrite, Category = "Stats")
    int32 CDefense;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCDefense() {return CDefense;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCDefense(int32 Defense) {CDefense = Defense;}
	
    // Movement speed
    UPROPERTY(Replicated,BlueprintReadWrite, Category = "Stats")
    float CSpeed;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	float GetCSpeed() {return CSpeed;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCSpeed(float Speed) {CSpeed = Speed;}
	
    // Cooldown reduction
    UPROPERTY(Replicated,BlueprintReadWrite, Category = "Stats")
    float CCooldownReduction;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	float GetCCooldownReduction() {return CCooldownReduction;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCCooldownReduction(float CooldownReduction) {CCooldownReduction = CooldownReduction;}
	
    //Exp
    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Stats")
    int32 CCurrentExp;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCCurrentExp() {return CCurrentExp;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCCurrentExp(int32 Exp) {CCurrentExp = Exp;}
	
    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Stats")
    int32 CExperience;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCExperience() {return CExperience;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCExperience(int32 Exp) {CExperience = Exp;}
	UFUNCTION(Server,Reliable,BlueprintCallable, Category = "Stats")
	void AddExperience(int32 Amount);
	
    // Level
    UPROPERTY(Replicated,BlueprintReadWrite, Category = "Stats")
    int32 CLevel;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCLevel() {return CLevel;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCLevel(int32 Level) {CLevel = Level;}
	
    UPROPERTY(Replicated,BlueprintReadWrite, Category = "Stats")
    int32 CAbLevel;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	int32 GetCAbLevel() {return CAbLevel;}
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetCAbLevel(int32 Level) {CAbLevel = Level;}
	
    // Gold
    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Gold")
	int32 CGold;
	UFUNCTION(BlueprintCallable, Category = "Gold")
	int32 GetCGold() {return CGold;}
	UFUNCTION(BlueprintCallable, Category = "Gold")
	void SetCGold(int32 Gold) {CGold = Gold;}

	UFUNCTION(Server,Reliable,BlueprintCallable, Category = "Gold")
	void AddGold(int32 Amount);
	
public:
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "Teams")
	E_TeamID TeamID;

	UPROPERTY(BlueprintReadWrite, Category = "Stats")
	int32 CKillCount;

	UPROPERTY(BlueprintReadWrite, Category = "Stats")
	int32 CDeathCount;
	
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void AddKillCount();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void AddDeathCount();
	
	void SetTeamID(E_TeamID NewTeamID){TeamID = NewTeamID;}
};
