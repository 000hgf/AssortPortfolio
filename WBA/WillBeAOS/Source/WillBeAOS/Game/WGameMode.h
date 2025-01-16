#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "WGameMode.generated.h"

UCLASS(config = Game)
class WILLBEAOS_API AWGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<class APlayerController*> AllPlayerController;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class AWGameState* WGS;

	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	TSoftObjectPtr<UWorld> L_MainMenu;

public:	
	void SpawnTower();
	void PlayerAssignTeam();
private:
	TMap<AActor*, int32> TeamMap;      // 팀정보 맵

public:
	// 팀 할당
	void AssignTeam(AActor* Actor, int32 TeamID);
	
	// 팀 검색
	int32 GetTeam(AActor* Actor) const;

	
protected:
	virtual void BeginPlay();
	virtual void PostLogin(APlayerController* NewPlayer);
	virtual void HandleMatchHasStarted() override;
	virtual void HandleMatchHasEnded() override;
	virtual bool ReadyToStartMatch_Implementation() override;
	virtual bool ReadyToEndMatch_Implementation() override;
	virtual void Logout(AController* Exiting) override;
	virtual void SwapPlayerControllers(APlayerController* OldPC, APlayerController* NewPC) override;

};
