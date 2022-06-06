// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveEnemigaEscuadrilla_01.h"
#include "NaveEnemigaEscuadrilla_02.h"
#include "NaveEnemigaEscuadrilla_03.h"
#include "NaveEscuadrillasCazaBuilder.h"
#include "DirectorNaveEscuadrillasBuilder.h"


AStarFighterGameModeBase::AStarFighterGameModeBase()
{

}

void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();

	//Spawn Builder and Engineer
    NaveEscuadrillasCazaBuilder = GetWorld()->SpawnActor<ANaveEscuadrillasCazaBuilder>(ANaveEscuadrillasCazaBuilder::StaticClass());
	DirectorNaveEscuadrillasBuilder = GetWorld()->SpawnActor<ADirectorNaveEscuadrillasBuilder>(ADirectorNaveEscuadrillasBuilder::StaticClass());

	////Set the Builder for the Engineer and create the buildings
	DirectorNaveEscuadrillasBuilder->SetNaveEscuadrillasBuilder(NaveEscuadrillasCazaBuilder);

	DirectorNaveEscuadrillasBuilder->ConstruirNaveEnemigaEscuadrilla_01();
	DirectorNaveEscuadrillasBuilder->ConstruirNaveEnemigaEscuadrilla_02();
	DirectorNaveEscuadrillasBuilder->ConstruirNaveEnemigaEscuadrilla_03();

	//Get the Engineer's Lodging and Logs the created buildings
	ANaveEnemigaEscuadrilla_01* NaveEnemiga01 = DirectorNaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_01();
	NaveEnemiga01->CaracteristicasNaveEnemigaEscuadrilla_01();

	ANaveEnemigaEscuadrilla_02* NaveEnemiga02 = DirectorNaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_02();
	NaveEnemiga02->CaracteristicasNaveEnemigaEscuadrilla_02();

	ANaveEnemigaEscuadrilla_03* NaveEnemiga03 = DirectorNaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_03();
	NaveEnemiga03->CaracteristicasNaveEnemigaEscuadrilla_03();

	//ANaveEnemigaEscuadrilla_01 = GetWorld()->SpawnActor<ANaveEnemigaEscuadrilla_01>(ANaveEnemigaEscuadrilla_01::StaticClass());
	//ANaveEnemigaEscuadrilla_01->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

