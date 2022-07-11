// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyDesplazar.h"

// Sets default values
AStrategyDesplazar::AStrategyDesplazar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeedNaveBatallador = 1000.0f;

	MovingAX = 0.0f;
	MovingAY = 0.0f;
}

// Called when the game starts or when spawned
void AStrategyDesplazar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyDesplazar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovingAX = rand() % 20 - 10;
	MovingAY = rand() % 20 - 10;

	const FVector MoveDirection = FVector(MovingAX, MovingAY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeedNaveBatallador;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}

void AStrategyDesplazar::Maneuver()
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("La NaveEnemigo tendra la Estrategia de Desplazarse"));

}

