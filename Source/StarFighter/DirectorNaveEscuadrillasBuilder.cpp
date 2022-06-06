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

void ADirectorNaveEscuadrillasBuilder::ConstruirNaveEnemigaEscuadrilla_01()
{
	if (!NaveEscuadrillasBuilder)
	{
		UE_LOG(LogTemp, Warning, TEXT("ConstruirNaveEnemigaEscuadrilla_01(): NaveEscuadrillasBuilder es NULL, inicializar correctamente esta clase"));
	}


	NaveEscuadrillasBuilder->BuildVelocidad_Movimiento();
	NaveEscuadrillasBuilder->BuildResistencia_Vida();
	NaveEscuadrillasBuilder->BuildSistemaRotacion();
	NaveEscuadrillasBuilder->BuildSistemaEscudo();
}

void ADirectorNaveEscuadrillasBuilder::ConstruirNaveEnemigaEscuadrilla_02()
{
	if (!NaveEscuadrillasBuilder)
	{
		UE_LOG(LogTemp, Warning, TEXT("ConstruirNaveEnemigaEscuadrilla_02(): NaveEscuadrillasBuilder es NULL, inicializar correctamente esta clase"));
	}

	NaveEscuadrillasBuilder->BuildNivelInvasion();
	NaveEscuadrillasBuilder->BuildNivelDisparo();
	NaveEscuadrillasBuilder->BuildSistemaEscudo();
	NaveEscuadrillasBuilder->BuildSistemaMuniciones();
}

void ADirectorNaveEscuadrillasBuilder::ConstruirNaveEnemigaEscuadrilla_03()
{
	if (!NaveEscuadrillasBuilder)
	{
		UE_LOG(LogTemp, Warning, TEXT("ConstruirNaveEnemigaEscuadrilla_03(): NaveEscuadrillasBuilder es NULL, inicializar correctamente esta clase"));
	}

	NaveEscuadrillasBuilder->BuildBombardeo();
	NaveEscuadrillasBuilder->BuildDesaparecer();
	NaveEscuadrillasBuilder->BuildSistemaCrecer();
}

void ADirectorNaveEscuadrillasBuilder::SetNaveEscuadrillasBuilder(AActor* Builder)
{
	NaveEscuadrillasBuilder = Cast<INaveEscuadrillasBuilder>(Builder);
	if (!NaveEscuadrillasBuilder)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("invalido ")));

		UE_LOG(LogTemp, Warning, TEXT("ConstruirNaveEnemigaEscuadrillas(): NaveEscuadrillasBuilder es NULL, inicializar correctamente esta clase"));
	}
}

ANaveEnemigaEscuadrilla_01* ADirectorNaveEscuadrillasBuilder::GetNaveEnemigaEscuadrilla_01()
{
	if (NaveEscuadrillasBuilder)
	{
		return NaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_01();

	}

	UE_LOG(LogTemp, Warning, TEXT("GetNaveEnemigaEscuadrilla_01(): retorna NULL"));
	return nullptr;
}

ANaveEnemigaEscuadrilla_02* ADirectorNaveEscuadrillasBuilder::GetNaveEnemigaEscuadrilla_02()
{
	if (NaveEscuadrillasBuilder)
	{
		return NaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_02();

	}

	UE_LOG(LogTemp, Warning, TEXT("GetNaveEnemigaEscuadrilla_02(): retorna NULL"));
	return nullptr;
}

ANaveEnemigaEscuadrilla_03* ADirectorNaveEscuadrillasBuilder::GetNaveEnemigaEscuadrilla_03()
{
	if (NaveEscuadrillasBuilder)
	{
		return NaveEscuadrillasBuilder->GetNaveEnemigaEscuadrilla_03();

	}

	UE_LOG(LogTemp, Warning, TEXT("GetNaveEnemigaEscuadrilla_03(): retorna NULL"));
	return nullptr;
}


