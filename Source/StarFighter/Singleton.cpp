// Fill out your copyright notice in the Description page of Project Settings.


#include "Singleton.h"
#include "NaveAereaEnemigoNodriza.h"

// Sets default values
ASingleton::ASingleton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASingleton::BeginPlay()
{
	Super::BeginPlay();
	
	//Create 4 mother enemy airship
	// Crear 4 naves enemigas 
	for (int i = 0; i <= 4; i++)
	{
		ANaveAereaEnemigoNodriza* SpawnedNaveEnemigo = GetWorld() -> SpawnActor<ANaveAereaEnemigoNodriza>(ANaveAereaEnemigoNodriza::StaticClass());
		if (SpawnedNaveEnemigo)
		{
			//If the Spawn succeeds, set the Spawned mother enemy airship to the local one
			//and log the success string
			//Si el Spawn tiene éxito, establezca la Nave Enemigo Spawned en el local y registra la cadena de éxito
			NaveAereaEnemigoNodriza = SpawnedNaveEnemigo;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Nave Enemigo Creado "), *NaveAereaEnemigoNodriza->GetName()));
		}
	}
}

// Called every frame
void ASingleton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

