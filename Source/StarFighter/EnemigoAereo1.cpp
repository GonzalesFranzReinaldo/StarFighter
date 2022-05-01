// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo1.h"


AEnemigoAereo1::AEnemigoAereo1()
{
	SpeedScale = 0.0f;
}

void AEnemigoAereo1::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoAereo1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

}
