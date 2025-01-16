#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WCharacterHUD.generated.h"

class UTextBlock;

UCLASS()
class WILLBEAOS_API UWCharacterHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, Category = "Character")
	class AWCharacterBase* AWC;//캐릭터 받아오는 함수
	UPROPERTY(BlueprintReadOnly, Category = "GameState")
	class AWGameState* AWGS;//게임스테이트
	UPROPERTY(BlueprintReadOnly, Category = "PlayerState")
	class AWPlayerState* AWPS;

	UFUNCTION(BlueprintCallable, Category = "Initialize")
	void UpdateCharacter(class AWCharacterBase* Char);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Health")
	TObjectPtr<class UProgressBar>HealthBar;
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthBarPercentage();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Tower")
	TObjectPtr<class UProgressBar>FriendTowerProgress;//아군 타워 진행상황
	UFUNCTION(BlueprintPure, Category = "Tower")
	float SetTowerProgress();//타워 진행상황 받아오는 함수
							 //추후 피아 식별 후 수정

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Nexus")
	TObjectPtr<class UProgressBar>FriendNexusHealth;//아군 타워 진행상황
	UFUNCTION(BlueprintPure, Category = "Nexus")
	float SetNexusHealth();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "GameTimer")
	UTextBlock* GameTimer;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "GameTimer")
	FText UpdateGameTimer();

	//UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Aim")
	//class URadialSlider* AimBound;
	//UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Aim")
	//float CanAttackEnemy();

	//스킬데이터 구조체
	struct FSkillCooldownData
	{
		float SkillCooldown;
		float CurrentSkillCooldown;
		UProgressBar* SkillProgress;
		UTextBlock* SkillTimer;
	};

	void SetSkillTimer(FSkillCooldownData& SkillData);
	FText ShowSkillTimer(FSkillCooldownData& SkillData);
	float ShowSkillProgress(FSkillCooldownData& SkillData);

	FSkillCooldownData SkillLData;
	FSkillCooldownData SkillRData;

	//평타(LeftClick)쿨타임
	UPROPERTY(BlueprintReadWrite, Category = "Skill_L")
	float SkillLCooldown = 0.5f;
	FTimerHandle CooldownLTimerHandle;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Skill_L")
	TObjectPtr<class UProgressBar>Skill_LProgress;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Skill_L")
	UTextBlock* Skill_LTimer;
	UFUNCTION(BlueprintCallable, Category = "Skill_L")
	void SetSkillLTimer();
	UFUNCTION(BlueprintPure, Category = "Skill_L")
	FText ShowSkillLTimer();
	UFUNCTION(BlueprintPure, Category = "Skill_L")
	float ShowSkillLProgress();
	UFUNCTION(BlueprintCallable, Category = "Skill_L")
	void UpdateSkillLTimer();

	//스킬R(RightClick)쿨타임
	UPROPERTY(BlueprintReadWrite, Category = "Skill_L")
	float SkillRCooldown = 3.0f;
	FTimerHandle CooldownRTimerHandle;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Skill_R")
	TObjectPtr<class UProgressBar>Skill_RProgress;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Skill_R")
	UTextBlock* Skill_RTimer;
	UFUNCTION(BlueprintCallable, Category = "Skill_R")
	void SetSkillRTimer();
	UFUNCTION(BlueprintPure, Category = "Skill_R")
	FText ShowSkillRTimer();
	UFUNCTION(BlueprintPure, Category = "Skill_R")
	float ShowSkillRProgress();
	UFUNCTION(BlueprintCallable, Category = "Skill_R")
	void UpdateSkillRTimer();





	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* Power;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetPower();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* CriticalChance;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetCC();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* AdditionalHealth;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetAH();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* Defence;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetDefence();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* Speed;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetSpeed();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* CooldownReducion;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetCR();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* Level;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetLevel();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* Exp;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetExp();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* Gold;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetGold();
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Stat")
	UTextBlock* AbilityLevel;
	UFUNCTION(Blueprintpure, meta = (BindWidget), Category = "Stat")
	FText SetAbLevel();

protected:
	// 위젯 초기화 시 실행되는 함수
	virtual void NativeConstruct() override;
};
