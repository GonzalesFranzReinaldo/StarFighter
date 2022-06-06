// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveEnemigaEscuadrilla_02.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveEnemigaEscuadrilla_02 : public ANave
{
	GENERATED_BODY()

private:
	FString NivelInvasion;
	FString NivelDisparo;
	FString SistemaGravedad;
	FString SistemaMuniciones;

public:

	void SetNivelInvasion(FString _NivelInvasion) { NivelInvasion = _NivelInvasion; }
	void SetNivelDisparo(FString _NivelDisparo) { NivelDisparo = _NivelDisparo; }
	void SetSistemaGravedad(FString _SistemaGravedad) { SistemaGravedad = _SistemaGravedad; }
	void SetSistemaMuniciones(FString _SistemaMuniciones) { SistemaMuniciones = _SistemaMuniciones; }

	//Declarar las caracteristica del Nave Enemigo
	void CaracteristicasNaveEnemigaEscuadrilla_02();

};
