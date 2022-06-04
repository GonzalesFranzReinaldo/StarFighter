// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveEnemigaEspacial.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveEnemigaEspacial : public ANave
{
	GENERATED_BODY()
	
private:

	// Estos se convertiran en clases
	FString Velocidad_Movimiento;
	FString Resistencia_Vida;
	FString SistemaRotacion;
	FString SistemaNivelDano;
	FString SistemaEscudo;

public:
	// Metodos accesores para registrar
	void SetVelocidad_Movimiento(FString _Velocidad_Movimiento) { Velocidad_Movimiento = _Velocidad_Movimiento; }
	void SetResistencia_Vida(FString _Resistencia_Vida) { Resistencia_Vida = _Resistencia_Vida; }
	void SetSistemaRotacion(FString _SistemaRotacion) { SistemaRotacion = _SistemaRotacion; }
	void SetSistemaNivelDano(FString _SistemaNivelDano) { SistemaNivelDano = _SistemaNivelDano; }
	void SetSistemaEscudo(FString _SistemaEscudo) { SistemaEscudo = _SistemaEscudo; }
	void CaracteristicasNaveEnemigaEspacial();
};
