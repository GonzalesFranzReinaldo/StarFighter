// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorNaveEscuadrillasBuilder.h"

// Sets default values
ADirectorNaveEscuadrillasBuilder::ADirectorNaveEscuadrillasBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorNaveEscuadrillasBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorNaveEscuadrillasBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorNaveEscuadrillasBuilder::ConstruirNaveEnemigaEspacial()
{
	if (!NaveEscuadrillasBuilder)
	{
		UE_LOG(LogTemp, Warning, TEXT("ConstruirNaveEnemiga(): NaveEscuadrillasBuilder es NULL, asegurese de inicializar correctamente esta clase"));
	}


	NaveEscuadrillasBuilder->BuildVelocidad_Movimiento();
	NaveEscuadrillasBuilder->BuildResistencia_Vida();
	NaveEscuadrillasBuilder->BuildSistemaRotacion();
	NaveEscuadrillasBuilder->BuildSistemaEscudo();
}

void ADirectorNaveEscuadrillasBuilder::SetNaveEscuadrillasBuilder(AActor* Builder)
{
	NaveEscuadrillasBuilder = Cast<INaveEscuadrillasBuilder>(Builder);
	if (!NaveEscuadrillasBuilder)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("invalido ")));

		UE_LOG(LogTemp, Warning, TEXT("ConstruirNaveEnemigaEspacial(): NaveEscuadrillasBuilder es NULL, asegurese de inicializar correctamente esta clase"));
	}
}

ANaveEnemigaEspacial* ADirectorNaveEscuadrillasBuilder::GetNaveEnemigaEspacial()
{
	if (NaveEscuadrillasBuilder)
	{
		return NaveEscuadrillasBuilder->GetNaveEnemigaEspacial();

	}

	UE_LOG(LogTemp, Warning, TEXT("GetNaveEnemigaEspacial(): retorna NULL"));
	return nullptr;
}

