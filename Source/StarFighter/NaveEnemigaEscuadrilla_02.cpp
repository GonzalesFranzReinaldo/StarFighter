// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEscuadrilla_02.h"

void ANaveEnemigaEscuadrilla_02::CaracteristicasNaveEnemigaEscuadrilla_02()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s "), *NivelInvasion));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s "), *NivelDisparo));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s "), *SistemaGravedad));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s "), *SistemaMuniciones));
}
