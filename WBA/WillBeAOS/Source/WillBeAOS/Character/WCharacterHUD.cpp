#include "WCharacterHUD.h"
#include "WCharacterBase.h"
#include "GameFramework/PlayerState.h"
#include "WPlayerState.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "../Game/WGameState.h"

void UWCharacterHUD::NativeConstruct()
{
	Super::NativeConstruct();

	AWGS = GetWorld()->GetGameState<AWGameState>();

	AWC = Cast<AWCharacterBase>(GetOwningPlayerPawn());
	if (AWC)
	{
		AWC->DSkillLCooldown.BindUObject(this, &ThisClass::SetSkillLTimer);
	}

	APlayerController* PlayerController = GetOwningPlayer();
	if (PlayerController)
	{
		AWPS = Cast<AWPlayerState>(PlayerController->PlayerState);
	}
}

void UWCharacterHUD::UpdateCharacter(AWCharacterBase* Char)
{
	AWC = Char;

	if (AWC)
	{
		AWC->DSkillLCooldown.BindUObject(this, &ThisClass::SetSkillLTimer);
	}
}

float UWCharacterHUD::GetHealthBarPercentage()
{
	if (AWC != nullptr)
	{
		if (AWC->GetHpPercentage() == 0)
		{
			SetVisibility(ESlateVisibility::Hidden);
		}
		return AWC->GetHpPercentage();
	}
	else return 0.0f;
}


float UWCharacterHUD::SetTowerProgress()
{
	if (AWGS != nullptr)
	{
		if (AWGS->GetTowerNum() == 0)
		{
			FriendTowerProgress->SetVisibility(ESlateVisibility::Hidden);
		}
		return (AWGS->GetTowerNum()/6.0f);
	}
	else return 0.5f;
}

float UWCharacterHUD::SetNexusHealth()
{
	if (AWGS != nullptr)
	{
		return AWGS->GetNexusHP();
	}
	return 0.0f;
}

FText UWCharacterHUD::UpdateGameTimer()
{
	float CurrentGameTime = AWGS->GetServerWorldTimeSeconds();
	float OneGametime = 45 * 60;
	float RestGameTime = OneGametime - CurrentGameTime;

	FString TimeString = FString::Printf(TEXT("%d : %02d"), static_cast<int32>(RestGameTime/60) , static_cast<int32>(FMath::Fmod(RestGameTime, 60)));
	return FText::FromString(TimeString);
}

//float UWCharacterHUD::CanAttackEnemy()
//{
//	return 0.0f;
//}

void UWCharacterHUD::SetSkillLTimer()
{
	CurrentSkillLCooldown = SkillLCooldown;
	GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, this, &ThisClass::UpdateSkillLTimer, 0.1f, true);
}

FText UWCharacterHUD::ShowSkillLTimer()
{
	FString CooldownString = FString::Printf(TEXT("%.1f"), CurrentSkillLCooldown);
	return FText::FromString(CooldownString);
}

float UWCharacterHUD::ShowSkillLProgress()
{
	return CurrentSkillLCooldown/SkillLCooldown;
}

void UWCharacterHUD::UpdateSkillLTimer()
{
	//0으로 지정할시 -0.1에 clear됨...
	//왜지...
	//0.1f에 지정했더니 0.0에 제대로 들어감

	if (CurrentSkillLCooldown <= 0.1f)
	{
		GetWorld()->GetTimerManager().ClearTimer(CooldownTimerHandle);
		Skill_LProgress->SetVisibility(ESlateVisibility::Hidden);
		Skill_LTimer->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		CurrentSkillLCooldown -= 0.1f;
		Skill_LProgress->SetVisibility(ESlateVisibility::Visible);
		Skill_LTimer->SetVisibility(ESlateVisibility::Visible);
	}

}

FText UWCharacterHUD::SetPower()
{
	if (AWPS)
	{
		FString PowerString = FString::Printf(TEXT("Attack: %d"), AWPS->CPower);
		return FText::FromString(PowerString);
	}
	return FText::FromString(TEXT("Attack: 0"));
}

FText UWCharacterHUD::SetCC()
{
	if (AWPS)
	{
		FString CCString = FString::Printf(TEXT("Crit: % d"), AWPS->CCriticalHitChance);
		return FText::FromString(CCString);
	}
	return FText::FromString(TEXT("Crit: 0"));
}

FText UWCharacterHUD::SetAH()
{
	if (AWPS)
	{
		FString AHString = FString::Printf(TEXT("AddHealth: % d"), AWPS->CAdditionalHealth);
		return FText::FromString(AHString);
	}
	return FText::FromString(TEXT("AddHealth: 0"));
}

FText UWCharacterHUD::SetDefence()
{
	if (AWPS)
	{
		FString DefenceString = FString::Printf(TEXT("Def: %d"), AWPS->CDefense);
		return FText::FromString(DefenceString);
	}
	return FText::FromString(TEXT("Def: 0"));
}

FText UWCharacterHUD::SetSpeed()
{
	if (AWPS)
	{
		FString SpeedString = FString::Printf(TEXT("Speed: %.1f"), AWPS->CSpeed);
		return FText::FromString(SpeedString);
	}
	return FText::FromString(TEXT("Speed: 0"));
}

FText UWCharacterHUD::SetCR()
{
	if (AWPS)
	{
		FString CRString = FString::Printf(TEXT("Cooldown: %.1f"), AWPS->CCooldownReduction);
		return FText::FromString(CRString);
	}
	return FText::FromString(TEXT("Cooldown: 0"));
}

FText UWCharacterHUD::SetLevel()
{
	if (AWPS)
	{
		FString LevelString = FString::Printf(TEXT("Lv.%d"), AWPS->CLevel);
		return FText::FromString(LevelString);
	}
	return FText();
}

FText UWCharacterHUD::SetExp()
{
	if (AWPS)
	{
		FString ExpString = FString::Printf(TEXT("%d / %d"), AWPS->CCurrentExp ,AWPS->CExperience);
		return FText::FromString(ExpString);
	}
	return FText();
}

FText UWCharacterHUD::SetGold()
{
	if (AWPS)
	{
		FString GoldString = FString::Printf(TEXT("Gold: %d"), AWPS->CGold);
		return FText::FromString(GoldString);
	}
	return FText();
}

FText UWCharacterHUD::SetAbLevel()
{
	if (AWPS)
	{
		FString AbString = FString::Printf(TEXT("ALv.: %d"), AWPS->CAbLevel);
		return FText::FromString(AbString);
	}
	return FText();
}
