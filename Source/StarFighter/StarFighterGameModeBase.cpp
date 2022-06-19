// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveEnemigaEscuadrilla_01.h"
#include "NaveEnemigaEscuadrilla_02.h"
#include "NaveEnemigaEscuadrilla_03.h"
#include "NaveEscuadrillasCazaBuilder.h"
#include "DirectorNaveEscuadrillasBuilder.h"

#include "GeneradorCapsulas.h"
#include "Capsula.h"
#include "GeneradorCapsulasArmas.h"
#include "GeneradorCapsulasEnergia.h"
#include "NaveEspacial.h"
#include "NaveEnemigaEspacial.h"


AStarFighterGameModeBase::AStarFighterGameModeBase()
{

}


void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SpawnNaveEnemigaEspacial();

	//SpawnCapsulas();

	AGeneradorCapsulas* GeneradorArmas = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
	ACapsula* capsula = GeneradorArmas->GetCapsula("Arma1");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Frabrica Capsula %s"), *capsula->GetNombre()));

	//Create the Shops
	AGeneradorCapsulas* GeneradorCapsulaEscudo = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
	ACapsula* Capsula = GeneradorCapsulaEscudo->GetCapsula("Escudo1");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	//Create the Shops
	AGeneradorCapsulas* GeneradorCapsulaEnergia = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	ACapsula* Capsula1 = GeneradorCapsulaEnergia->GetCapsula("Energia1");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Capsula generada %s"), *Capsula1->GetNombre()));

	//Create the Shops
	AGeneradorCapsulas* GeneradorCapsulaVida = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	ACapsula* Capsula2 = GeneradorCapsulaVida->GetCapsula("Vida1");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue,FString::Printf(TEXT("Capsula generada %s"), *Capsula2->GetNombre()));

	/*UWorld* const World = GetWorld();

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
	NaveEnemiga03->CaracteristicasNaveEnemigaEscuadrilla_03();*/

	//ANaveEnemigaEscuadrilla_01 = GetWorld()->SpawnActor<ANaveEnemigaEscuadrilla_01>(ANaveEnemigaEscuadrilla_01::StaticClass());
	//ANaveEnemigaEscuadrilla_01->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AStarFighterGameModeBase::SpawnNaveEnemigaEspacial()
{

	UWorld* const World = GetWorld();
	World->SpawnActor<ANaveEnemigaEspacial>(FVector(400.0f, -400.0f, 200), FRotator::ZeroRotator);
}

void AStarFighterGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Creando Enemiga Nave Espacial"));
	float newX = rand() % 100 + 1;
	float newY = rand() % 100 + 1;
	UWorld* const World = GetWorld();
	World->SpawnActor<ANaveEnemigaEspacial>(FVector(newX, newY, 200), FRotator::ZeroRotator);
}