// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo2.h"

AEnemigoAereo2::AEnemigoAereo2()
{
	SpeedScale = 0.0f;
}

void AEnemigoAereo2::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoAereo2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

}
