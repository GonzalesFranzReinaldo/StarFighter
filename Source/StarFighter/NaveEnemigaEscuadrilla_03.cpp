// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEscuadrilla_03.h"

void ANaveEnemigaEscuadrilla_03::CaracteristicasNaveEnemigaEscuadrilla_03()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("%s"), *Bombardeo));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("%s"), *Desaparecer));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("%s"), *SistemaCrecer));
	
}
