// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo3.h"

AEnemigoAereo3::AEnemigoAereo3()
{
	SpeedScale = 0.0f;
}

void AEnemigoAereo3::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoAereo3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

	FVector NewLocation2 = GetActorLocation();
	float DeltaForward = (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));
	NewLocation2.X += DeltaForward * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation2);
}

