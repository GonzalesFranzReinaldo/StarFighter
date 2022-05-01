// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveTerrestre.h"
#include "EnemigoTerrestre1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoTerrestre1 : public ANaveTerrestre
{
	GENERATED_BODY()

public:
     // Sets default values for this actors properties
	AEnemigoTerrestre1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float Deltaseconds) override;

	float RunningTime;


};
