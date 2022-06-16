// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEscudo1.h"


// Called when the game starts or when spawned
void ACapsulaEscudo1::BeginPlay()
{
	Super::BeginPlay();

	Nombre = "Capsula Escudo 1";
	TipoCapsula = "Capsula de Proteccion";
	TipoEfecto = "Debelita el disparo del enemigo";
	TipoDuracion = "Mientra este Activo en el juego";
	TiempoDuracion = 10.0f;
}

void ACapsulaEscudo1::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de Energia 1"));
}
