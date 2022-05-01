// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestre1.h"

AEnemigoTerrestre1::AEnemigoTerrestre1()
{

}

void AEnemigoTerrestre1::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoTerrestre1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 30.0f;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}
