// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaArma1.h"


// Called when the game starts or when spawned
void ACapsulaArma1::BeginPlay()
{
	Super::BeginPlay();

	Nombre = "Capsula Arma 1";
	TipoCapsula = "Capasula de Fusil";
	TipoEfecto = "Incrementa numero y velocidad balas"; 
	TipoDuracion = "Mientra este Activo en el juego";
	TiempoDuracion = 10.0f;
}

void ACapsulaArma1::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Generando una capsula de Arma 1"));
}
