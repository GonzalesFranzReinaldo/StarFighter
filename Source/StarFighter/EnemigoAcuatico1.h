// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAcuatico.h"
#include "EnemigoAcuatico1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoAcuatico1 : public ANaveAcuatico
{
	GENERATED_BODY()
	
public:

	AEnemigoAcuatico1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(Editanywhere)
		float SpeedScale;

	float RunningTime;
};
