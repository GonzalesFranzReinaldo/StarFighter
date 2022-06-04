// Fill out your copyright notice in the Description page of Project Settings.


#include "ImplementarNaveEnemigaBuilder.h"
//#include "DirectorNaveEnemigaBuilder.h"
//#include "NaveEnemigaCazaBuilder.h"
//#include "NavesEnemigas.h"

// Sets default values
AImplementarNaveEnemigaBuilder::AImplementarNaveEnemigaBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AImplementarNaveEnemigaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
	// Es el main() del builder
	/*NaveEnemigaCazaBuilder = GetWorld()->SpawnActor<ANaveEnemigaCazaBuilder>(ANaveEnemigaCazaBuilder::StaticClass());
	DirectorNaveEnemigaBuilder = GetWorld()->SpawnActor<ADirectorNaveEnemigaBuilder>(ADirectorNaveEnemigaBuilder::StaticClass());

	DirectorNaveEnemigaBuilder->SetNaveEnemigaBuilder(NaveEnemigaCazaBuilder);
	DirectorNaveEnemigaBuilder->ConstruirNavesEnemigas();

	ANavesEnemigas* NavesEnemigas = DirectorNaveEnemigaBuilder->GetNavesEnemigas();
	NavesEnemigas->CaracteristicasNavesEnemigas();*/
}

// Called every frame
void AImplementarNaveEnemigaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

