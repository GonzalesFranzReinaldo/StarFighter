// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaEnergia1.h"


// Called when the game starts or when spawned
void ACapsulaEnergia1::BeginPlay()
{
	Super::BeginPlay();
	
	Nombre = "Capsula Energia 1";
	TipoCapsula = "Capsula de Resistencia";
	TipoEfecto = "Incrementa Energia el jugador";
	TipoDuracion = "Mientra este Activo en el juego";
	TiempoDuracion = 10.0f;
}

void ACapsulaEnergia1::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Generando una capsula de Energia 1"));
}
