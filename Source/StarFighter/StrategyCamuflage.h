// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrategyNave.h"
#include "StrategyCamuflage.generated.h"

UCLASS()
class STARFIGHTER_API AStrategyCamuflage : public AActor, public IStrategyNave
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrategyCamuflage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Ejecutar la Maniobra de esta Estatregia
	virtual void Maneuver() override;

};
