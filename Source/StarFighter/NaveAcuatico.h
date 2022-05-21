// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveAcuatico.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveAcuatico : public ANave
{
	GENERATED_BODY()

public: 
	ANaveAcuatico();

	float MovingTX;
	float MovingTY;
	
};
