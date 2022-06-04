// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NaveEnemigaBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNaveEnemigaBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTER_API INaveEnemigaBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Esta clase sera un interfas para la nave enemiga donde solo declaramos los metodos a construir
	virtual void BuildSistemaDefensa() = 0;
	virtual void BuildSistemaAtaque() = 0;
	virtual void BluidSistemaDesplazamiento() = 0;
	virtual void BluidSistemaCamuflaje() = 0;
	virtual class ANavesEnemigas* GetNavesEnemigas() = 0;
};
