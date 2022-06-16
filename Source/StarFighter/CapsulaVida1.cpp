// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaVida1.h"


// Called when the game starts or when spawned
void ACapsulaVida1::BeginPlay()
{
	Super::BeginPlay();

	Nombre = "Capsula Vida 1";
	TipoCapsula = "Capsula vida ";
	TipoEfecto = "Incrementa Vida al la capsula";
	TipoDuracion = "Mientra este Activo en el juego";
	TiempoDuracion = 10.0f;
}

void ACapsulaVida1::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Generando una capsula de Vida 1"));
}
