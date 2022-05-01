// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "EnemigoAereo1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoAereo1 : public ANaveAerea
{
	GENERATED_BODY()

public:

	AEnemigoAereo1();

	// Sets default values for this actor's properties
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(Editanywhere)
		float SpeedScale;

	float RunningTime;
};
