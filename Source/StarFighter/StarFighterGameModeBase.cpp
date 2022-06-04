// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NavesEnemigas.h"
#include "NaveEnemigaBuilder.h"
#include "DirectorNaveEnemigaBuilder.h" 
#include "NaveEnemigaCazaBuilder.h"


void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();


	// Es el main() del builder
	NaveEnemigaCazaBuilder = GetWorld()->SpawnActor<ANaveEnemigaCazaBuilder>(ANaveEnemigaCazaBuilder::StaticClass());
	DirectorNaveEnemigaBuilder = GetWorld()->SpawnActor<ADirectorNaveEnemigaBuilder>(ADirectorNaveEnemigaBuilder::StaticClass());

	DirectorNaveEnemigaBuilder->SetNaveEnemigaBuilder(NaveEnemigaCazaBuilder);
	DirectorNaveEnemigaBuilder->ConstruirNavesEnemigas();

	ANavesEnemigas* NavesEnemigas = DirectorNaveEnemigaBuilder->GetNavesEnemigas();
	NavesEnemigas->CaracteristicasNavesEnemigas();

}

