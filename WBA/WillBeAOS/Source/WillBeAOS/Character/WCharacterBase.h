#pragma once

#include "CoreMinimal.h"
#include "WDelegateDefine.h"
#include "GameFramework/Character.h"
#include "WCharacterBase.generated.h"

struct FInputActionValue;
class UInputAction;
class UAnimMontage;
class UWidgetComponent;

UCLASS()
class WILLBEAOS_API AWCharacterBase : public ACharacter
{

	GENERATED_BODY()

	//ì»´í¬?ŒíŠ¸
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"));
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"));
	class UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"));
	class UCombatComponent* CombatComp;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UWidgetComponent* WidgetComponent;


public:
	AWCharacterBase();
	//?…ë ¥ ?ì…‹
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* IMC_Asset;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_Look;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_Jump;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_Behavior;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* IA_SkillR;

	UPROPERTY(BlueprintReadonly)
	bool IsDead;

	UPROPERTY(BlueprintReadWrite, Category = "Health")
	UAnimMontage* DeadAnimMontage;	//ì£½ì„???°ì¼ ëª½í?ì£?
	UPROPERTY(BlueprintReadWrite, Category = "Health")
	UAnimMontage* HitAnimMontage;	//?¼ê²©???°ì¼ ëª½í?ì£?
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	TArray<UAnimMontage*> AttackMontages = {};	//ÄŞº¸¿¡ ¾²ÀÏ ¾Ö´Ô¸ùÅ¸ÁÖ ¹è¿­
	UPROPERTY(BlueprintReadWrite, Category = Combo)
	UAnimMontage* SkillRMontage;//R½ºÅ³¿¡ ¾²ÀÏ ¸ùÅ¸ÁÖ

	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
	void Behavior(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SkillR(const FInputActionValue& Value);

	//?¸ë¦¬ê²Œì´???¨ìˆ˜
	UFUNCTION(BlueprintCallable, Category = Dead)
	void BeingDead();//ì£½ì„???¸ë¦¬ê²Œì´?¸ë¡œ ?¸ì¶œ???¨ìˆ˜
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void HandleApplyPointDamage(FHitResult LastHit);//?¬ì¸???°ë?ì§€ë¥?ì¤„ì‹œ ?¸ë¦¬ê²Œì´?¸ë¡œ ?¸ì¶œ???¨ìˆ˜
	UFUNCTION(BlueprintCallable, Category = "Combat")//TakeDamage ?¨ìˆ˜ ?¤ë²„?¼ì´??
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

	//?¸ë¦¬ê²Œì´???•ì˜
	FDS_SkillLCooldown DSkillLCooldown;
	FDS_SkillLCooldown DSkillRCooldown;


protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	float CharacterDamage;	//?°ë?ì§€
	
public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
	float GetHpPercentage();
	UPROPERTY(BlueprintReadWrite, Category = "Skill")//Â÷ÈÄ ¼öÁ¤
	bool SkillREnable;
};
