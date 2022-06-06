// Fill out your copyright notice in the Description page of Project Settings.


#include "ImplentarNaveEscuadrillasBuilder.h"
#include "DirectorNaveEscuadrillasBuilder.h"
#include "NaveEscuadrillasCazaBuilder.h"

// Sets default values
AImplentarNaveEscuadrillasBuilder::AImplentarNaveEscuadrillasBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AImplentarNaveEscuadrillasBuilder::BeginPlay()
{
	Super::BeginPlay();
	
	NaveEscuadrillasCazaBuilder = GetWorld()->SpawnActor<ANaveEscuadrillasCazaBuilder>(ANaveEscuadrillasCazaBuilder::StaticClass());
	DirectorNaveEscuadrillasBuilder = GetWorld()->SpawnActor<ADirectorNaveEscuadrillasBuilder>(ADirectorNaveEscuadrillasBuilder::StaticClass());

	//DirectorNaveEscuadrillasBuilder->SetNaveEscuadrillasBuilder(NaveEscuadrillasCazaBuilder);

	DirectorNaveEscuadrillasBuilder->ConstruirNaveEnemigaEscuadrilla_01();
	DirectorNaveEscuadrillasBuilder->ConstruirNaveEnemigaEscuadrilla_02();
	DirectorNaveEscuadrillasBuilder->ConstruirNaveEnemigaEscuadrilla_03();

	// Implementar Nave Enmiga Escuadrilla 01
	ANaveEnemigaEscuadrilla_01* NaveEnemiga01 = DirectorNaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_01();
	NaveEnemiga01->CaracteristicasNaveEnemigaEscuadrilla_01();

	// Implementar Nave Enmiga Escuadrilla 01
	ANaveEnemigaEscuadrilla_02* NaveEnemiga02 = DirectorNaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_02();
	NaveEnemiga02->CaracteristicasNaveEnemigaEscuadrilla_02();

	// Implementar Nave Enmiga Escuadrilla 03
	ANaveEnemigaEscuadrilla_03* NaveEnemiga03 = DirectorNaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_03();
	NaveEnemiga03->CaracteristicasNaveEnemigaEscuadrilla_03();
}

// Called every frame
void AImplentarNaveEscuadrillasBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

