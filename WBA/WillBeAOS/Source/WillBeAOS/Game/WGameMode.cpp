#include "WGameMode.h"
#include "WGameState.h"
#include "Gimmick/Nexus.h"
#include "Gimmick/Tower.h"
#include "Gimmick/SpawnTowerPoint.h"
#include "Kismet/GameplayStatics.h"


void AWGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	
	if (NewPlayer)
	{
		AllPlayerController.Add(NewPlayer);
	}
}

void AWGameMode::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Mode BeginPlay called"));
	
	WGameState = Cast<AWGameState>(GetWorld()->GetGameState());
	if (WGameState != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("GameState is not called"));
	}

	SpawnTower();
	
}

void AWGameMode::SwapPlayerControllers(APlayerController* OldPC, APlayerController* NewPC)
{
	Super::SwapPlayerControllers(OldPC, NewPC);

	if (NewPC)
	{
		AllPlayerController.Add(NewPC);
	}
}

bool AWGameMode::ReadyToStartMatch_Implementation()
{
	Super::ReadyToStartMatch_Implementation();
	return true;
}

void AWGameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();
}

bool AWGameMode::ReadyToEndMatch_Implementation()
{
	Super::ReadyToEndMatch_Implementation();
	return WGameState != nullptr && WGameState->IsGameEnd;
}

void AWGameMode::HandleMatchHasEnded()
{
	Super::HandleMatchHasEnded();
}

void AWGameMode::Logout(AController* Exiting)
{
	if (APlayerController* PC = Cast<APlayerController>(Exiting))
	{
		AllPlayerController.Remove(PC);
	}
	Super::Logout(Exiting);
}

//-----------------------------------------------------------
//스폰 타워
//-----------------------------------------------------------

void AWGameMode::SpawnTower()
{
	TArray<AActor*> SpawnPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnTowerPoint::StaticClass(), SpawnPoints);

	for (AActor* SpawnPointActor : SpawnPoints)
	{
		ASpawnTowerPoint* SpawnPoint = Cast<ASpawnTowerPoint>(SpawnPointActor);
		
		if (HasAuthority() && SpawnPoint && SpawnPoint->TowerClass)
		{
			// 타워 생성
			FActorSpawnParameters SpawnParams;
			AActor* Tower = GetWorld()->SpawnActor<AActor>(
				SpawnPoint->TowerClass,
				SpawnPoint->GetActorLocation(),
				SpawnPoint->GetActorRotation(),
				SpawnParams
			);
			
			if (ATower* SpawnedTower = Cast<ATower>(Tower))
			{
				SpawnedTower->SetReplicates(true);
				SpawnedTower->TowerTeamID = SpawnPoint->TeamID;
				AssignTeam(SpawnedTower,static_cast<int32>(SpawnedTower->TowerTeamID));
			}
			else if (ANexus* SpawnedNexus = Cast<ANexus>(Tower))
			{	
				SpawnedNexus->SetReplicates(true);
				SpawnedNexus->NexusTeamID = SpawnPoint->TeamID;
				AssignTeam(SpawnedNexus,static_cast<int32>(SpawnedNexus->NexusTeamID));
			}
		}
	}
}

//-----------------------------------------------------------
//팀 관련 함수
//-----------------------------------------------------------

void AWGameMode::AssignTeam(AActor* Actor, int32 TeamID)
{
	if (!Actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid actor!"));
		return;
	}

	TeamMap.Add(Actor, TeamID);
	UE_LOG(LogTemp, Log, TEXT("Actor Add! %s %d"), *Actor->GetName(), TeamID);
	
	if (WGameState)
	{
	//	WGameState->UpdateTeamInfo(Actor, TeamID);
	}
}

int32 AWGameMode::GetTeam(AActor* Actor) const
{
	if (!Actor)
	{
		return -1; // Invalid actor
	}
	
	if (const int32* TeamID = TeamMap.Find(Actor))
	{
		return *TeamID;
	}

	return -1; // Team 정보 없음
}

void AWGameMode::RemoveTeam(AActor* Actor)
{
	if (!Actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid actor!"));
		return;
	}

	TeamMap.Remove(Actor);//팀 정보에서 지우기
}