// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorNaveEnemigaBuilder.h"
#include "NavesEnemigas.h"

// Sets default values
ADirectorNaveEnemigaBuilder::ADirectorNaveEnemigaBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorNaveEnemigaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorNaveEnemigaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorNaveEnemigaBuilder::ConstruirNavesEnemigas()
{
	if (NaveEnemigaBuilder)
	{
		UE_LOG(LogTemp, Error, TEXT("ConstruirNavesEnemigas(): NaveEnemigaBuilder es null, inicialice correctamente la clase."));
		return;
	}

	NaveEnemigaBuilder->BuildSistemaDefensa();
	NaveEnemigaBuilder->BuildSistemaAtaque();
	NaveEnemigaBuilder->BluidSistemaDesplazamiento();
	NaveEnemigaBuilder->BluidSistemaCamuflaje();
}

void ADirectorNaveEnemigaBuilder::SetNaveEnemigaBuilder(AActor* Builder)
{
	NaveEnemigaBuilder = Cast<INaveEnemigaBuilder>(Builder);

	if (!NaveEnemigaBuilder)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Invalido"));
		UE_LOG(LogTemp, Error, TEXT("ConstruirNavesEnemigas(): NaveEnemigaBuilder es null, inicialice correctamente la clase."));
		return;
	}
}

ANavesEnemigas* ADirectorNaveEnemigaBuilder::GetNavesEnemigas()
{
	if (NaveEnemigaBuilder) {
		return NaveEnemigaBuilder->GetNavesEnemigas();
	}

	UE_LOG(LogTemp, Error, TEXT("GetNavesEnemigas(): Retorna nullptr."));

	return nullptr;
}

