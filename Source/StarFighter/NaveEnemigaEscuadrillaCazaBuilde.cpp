// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEscuadrillaCazaBuilde.h"
#include "NaveEnemigaEspacial.h"

// Sets default values
ANaveEnemigaEscuadrillaCazaBuilde::ANaveEnemigaEscuadrillaCazaBuilde()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANaveEnemigaEscuadrillaCazaBuilde::BeginPlay()
{
	Super::BeginPlay();

	NaveEnemigaEspacial = GetWorld()->SpawnActor<ANaveEnemigaEspacial>(ANaveEnemigaEspacial::StaticClass());
	NaveEnemigaEspacial->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called every frame
void ANaveEnemigaEscuadrillaCazaBuilde::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANaveEnemigaEscuadrillaCazaBuilde::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANaveEnemigaEscuadrillaCazaBuilde::BuildVelocidad_Movimiento()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildVelocidad_Movimiento(): NaveEnemigaEspacial es null, inicialice correctamente la clase."));
		return;
	}

	NaveEnemigaEspacial->SetVelocidad_Movimiento("Velocidad_Movimiento Caza");
}

void ANaveEnemigaEscuadrillaCazaBuilde::BuildResistencia_Vida()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildResistencia_Vida(): NaveEnemigaEspacial es null, inicialice correctamente la clase."));
		return;
	}

	NaveEnemigaEspacial->SetResistencia_Vida("Resistencia_Vida Caza");
}

void ANaveEnemigaEscuadrillaCazaBuilde::BuildSistemaRotacion()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaRotacion(): NaveEnemiga es null, inicialice correctamente la clase."));
		return;
	}

	NaveEnemigaEspacial->SetSistemaRotacion("Sistema Rotacion Caza");
}

void ANaveEnemigaEscuadrillaCazaBuilde::BuildSistemaNivelDano()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaNiveDano(): NaveEnemiga es null, inicialice correctamente la clase."));
		return;
	}

	NaveEnemigaEspacial->SetSistemaNivelDano("Sistema Nivel Dano Caza");
}

void ANaveEnemigaEscuadrillaCazaBuilde::BuildSistemaEscudo()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaEscudo(): NaveEnemiga es null, inicialice correctamente la clase."));
		return;
	}

	NaveEnemigaEspacial->SetSistemaEscudo("Sistema Escudo Caza");
}

ANaveEnemigaEspacial* ANaveEnemigaEscuadrillaCazaBuilde::GetNaveEnemigaEspacial()
{
	return NaveEnemigaEspacial;
}

