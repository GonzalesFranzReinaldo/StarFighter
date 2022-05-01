// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestre2.h"

AEnemigoTerrestre2::AEnemigoTerrestre2()
{

}

void AEnemigoTerrestre2::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoTerrestre2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * 30.0f;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}
