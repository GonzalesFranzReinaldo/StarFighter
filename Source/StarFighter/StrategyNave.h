// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "StrategyNave.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UStrategyNave : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTER_API IStrategyNave
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//The pure virtual functions of the StrategyNave
	virtual void Maneuver() = 0;   // Funcion Maniobra
};
