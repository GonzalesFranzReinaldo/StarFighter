// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveEnemigaEscuadrilla_01.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveEnemigaEscuadrilla_01 : public ANave
{
	GENERATED_BODY()

private:

	// Estos se convertiran en clases o metodos funciones
	FString Velocidad_Movimiento;
	FString Resistencia_Vida;
	FString SistemaRotacion;
	FString SistemaEscudo;

public:
	// Metodos accesores para registrar
	void SetVelocidad_Movimiento(FString _Velocidad_Movimiento) { Velocidad_Movimiento = _Velocidad_Movimiento; }
	void SetResistencia_Vida(FString _Resistencia_Vida) { Resistencia_Vida = _Resistencia_Vida; }
	void SetSistemaRotacion(FString _SistemaRotacion) { SistemaRotacion = _SistemaRotacion; }
	void SetSistemaEscudo(FString _SistemaEscudo) { SistemaEscudo = _SistemaEscudo; }

	void CaracteristicasNaveEnemigaEscuadrilla_01();
};
