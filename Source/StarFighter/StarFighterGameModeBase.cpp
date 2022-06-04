// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveEnemigaEspacial.h"
#include "NaveEscuadrillasCazaBuilder.h"
#include "DirectorNaveEscuadrillasBuilder.h"



AStarFighterGameModeBase::AStarFighterGameModeBase()
{

}

void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	/*UWorld* const World = GetWorld();

	//Spawn Builder and Engineer
	NaveEscuadrillasCazaBuilder = GetWorld()->SpawnActor<ANaveEscuadrillasCazaBuilder>(ANaveEscuadrillasCazaBuilder::StaticClass());
	Director = GetWorld()->SpawnActor<ADirectorNaveEscuadrillasBuilder>(ADirectorNaveEscuadrillasBuilder::StaticClass());

	//Set the Builder for the Engineer and create the buildings
	Director->SetNaveEscuadrillasBuilder(NaveEscuadrillasCazaBuilder);
	Director->ConstruirNaveEnemigaEspacial();

	//Get the Engineer's Lodging and Logs the created buildings
	ANaveEnemigaEspacial* NaveEnemiga = Director->GetNaveEnemigaEspacial();
	NaveEnemiga->CaracteristicasNaveEnemigaEspacial();*/

	//NaveEnemigaEspacial = GetWorld()->SpawnActor<ANaveEnemigaEspacial>(ANaveEnemigaEspacial::StaticClass());
	//NaveEnemigaEspacial->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

