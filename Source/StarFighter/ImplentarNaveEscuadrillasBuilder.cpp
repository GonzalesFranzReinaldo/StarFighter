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


	DirectorNaveEscuadrillasBuilder->SetNaveEscuadrillasBuilder(NaveEscuadrillasCazaBuilder);
	DirectorNaveEscuadrillasBuilder->ConstruirNaveEnemigaEspacial();

	ANaveEnemigaEspacial* NaveEnemiga = DirectorNaveEscuadrillasBuilder->GetNaveEnemigaEspacial();
	NaveEnemiga->CaracteristicasNaveEnemigaEspacial();
}

// Called every frame
void AImplentarNaveEscuadrillasBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

