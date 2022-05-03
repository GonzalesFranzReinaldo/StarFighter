 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Cola.h"
#include "Bala.generated.h"
#include "Engine.h"
//#include "GameFramework/Actor"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ABala : public AProyectil
{
	GENERATED_BODY()

public:
	ABala();

	// Sets default values for this actor's properties
	virtual void BeginPlay() override;

	// Called when the game stars or whwn spawned
	virtual void Tick(float Deltaseconds) override;

	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
	FVector Velocity = FVector(100.f);

	float BulletExpiry = 0;

	//Cola<class Proyectil*> ColaBalas;

	Cola<int> ColaEnteros;
	Cola<float> ColaFlotantes;
};
