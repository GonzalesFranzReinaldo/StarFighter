// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEscuadrilla_01.h"

void ANaveEnemigaEscuadrilla_01::CaracteristicasNaveEnemigaEscuadrilla_01()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s "), *Velocidad_Movimiento));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s "), *Resistencia_Vida));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s "), *SistemaRotacion));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s "), *SistemaEscudo));
}
