// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspacial.h"

void ANaveEnemigaEspacial::CaracteristicasNaveEnemigaEspacial()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *Velocidad_Movimiento));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *Resistencia_Vida));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *SistemaRotacion));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *SistemaNivelDano));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *SistemaEscudo));
}
