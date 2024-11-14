#include "WGameState.h"
#include "../Gimmick/Nexus.h"
#include "../Character/WCharacterBase.h"
#include "../Character/WPlayerController.h"
#include "Kismet/GameplayStatics.h"

void AWGameState::BeginPlay()
{
    Super::BeginPlay();
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Game State BeginPlay called"));
    }
    ANexus* EnemyNexus = GetNexus();
    if (EnemyNexus)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Found Nexus"));
    }
}

ANexus* AWGameState::GetNexus()
{
    ANexus* GameNexus;
    AActor* GetNexus = UGameplayStatics::GetActorOfClass(GetWorld(), ANexus::StaticClass());
    if (GetNexus)
    {
        GameNexus = Cast<ANexus>(GetNexus);
        return GameNexus;

    }
    return nullptr;
}

void AWGameState::HandleNexusDestroyed()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Nexus Destroyed!"));
    }

    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        AWPlayerController* PC = Cast<AWPlayerController>(It->Get());
        if (PC)
        {
            PC->GameHasEnded(nullptr, true);
        }
    }
}

void AWGameState::HandlePlayIsDead()
{
    
}

