// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NaveEnemigaEscuadrilla_01.h"
#include "NaveEnemigaEscuadrilla_02.h"
#include "NaveEnemigaEscuadrilla_03.h"
#include "NaveEscuadrillasBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNaveEscuadrillasBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTER_API INaveEscuadrillasBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Metodos para la NaveEnemigaEscuadrilla_01
	virtual void BuildVelocidad_Movimiento() = 0;
	virtual void BuildResistencia_Vida() = 0;
	virtual void BuildSistemaRotacion() = 0;
	virtual void BuildSistemaEscudo() = 0;

	virtual class ANaveEnemigaEscuadrilla_01* GetNaveEnemigaEscuadrilla_01() = 0;

	// Metodos para la NaveEnemigaEscuadrilla_02
	virtual void BuildNivelInvasion() = 0;
	virtual void BuildNivelDisparo() = 0;
	virtual void BuildSistemaGravedad() = 0;
	virtual void BuildSistemaMuniciones() = 0;

	virtual class ANaveEnemigaEscuadrilla_02* GetNaveEnemigaEscuadrilla_02() = 0;

	// Metodos para la NaveEnemigaEscuadrilla_03
	virtual void BuildBombardeo() = 0;
	virtual void BuildDesaparecer() = 0;
	virtual void BuildSistemaCrecer() = 0;

	virtual class ANaveEnemigaEscuadrilla_03* GetNaveEnemigaEscuadrilla_03() = 0;

};
