// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyDisparo.h"
#include "Proyectil.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AStrategyDisparo::AStrategyDisparo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GunOffset = FVector(90.f, 0.f, 0.f);  //para la distancia de aparicion de la bala.
	FireRate = 2.0f;
	bCanFire = true;
}

// Called when the game starts or when spawned
void AStrategyDisparo::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AStrategyDisparo::FireNave, 01.0f, true, 2.0f);
}

// Called every frame
void AStrategyDisparo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStrategyDisparo::Maneuver()
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("La Nave Enemiga tendra la Estrategia de Disparar"));
	//FireNave();
}

void AStrategyDisparo::FireNave()
{
	bCanFire = true;
	float RandX = rand() % 500 - 50;
	float RandY = rand() % 500 - 50;
	const FVector FireDirection = FVector(RandX, RandY, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotNave(FireDirection);
}

void AStrategyDisparo::FireShotNave(FVector FireDirection)
{
	if (bCanFire == true)
	{
		const FRotator FireRotation = FRotator(0.0, rand() % 500 - 50, 0.0);//toma una rotacion aleatoria 
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			World->SpawnActor<AProyectil>(SpawnLocation + FVector(50, -50, 0), FireRotation);
			World->SpawnActor<AProyectil>(SpawnLocation + FVector(-50, 50, 0), FireRotation);

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AStrategyDisparo::ShotTimerExpired, FireRate);
		}
	}

	/*if (bCanFire == true)
	{
		if (FireDirection.SizeSquared() > 0.0f)
		{

			const FRotator FireRotation = FRotator(0.0, rand() % 500 - 50, 0.0);
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);

				bCanFire = false;
				World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AStrategyDisparo::ShotTimerExpired, FireRate);
			}
		}
	}*/
}

void AStrategyDisparo::ShotTimerExpired()
{
	bCanFire = true;
}

