// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "EnemigoTrabajo.h"

void AStarFighterGameModeBase::SpawEnemigo()
{
	float newX = rand() % 100 + 1;
	float newY = rand() % 100 + 1;
	UWorld* const World = GetWorld();
	World->SpawnActor<AEnemigoTrabajo>(FVector(400.0f, -400.0f, 200), FRotator::ZeroRotator);
}

void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SpawEnemigo();
}
