// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuatico1.h"

AEnemigoAcuatico1::AEnemigoAcuatico1()
{
	SpeedScale = 0.0f;
}

void AEnemigoAcuatico1::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoAcuatico1::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));
	NewLocation.X += DeltaHeight * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
	
}
