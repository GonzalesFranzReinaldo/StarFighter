// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestre1.h"
#include "Proyectil.h"
#include "NaveAereaJugador.h"
#include "Kismet/GameplayStatics.h"

AEnemigoTerrestre1::AEnemigoTerrestre1()
{
	MoveSpeed = 100.0f;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 2.0f;
	bCanFire = true;
}

void AEnemigoTerrestre1::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AEnemigoTerrestre1::FireEnemigo, 01.0f, true, 3.0f);
}

void AEnemigoTerrestre1::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	srand(time(NULL));

	MovingTX = rand() % 20 - 10;
	MovingTY = rand() % 20 - 10;

	MoveSpeed = 20;


	const FVector MoveDirection = FVector(MovingTX, MovingTY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}


	// basic intel: move the monster towards the player
	ANaveAereaJugador* avatar = Cast<ANaveAereaJugador>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!avatar)
	{
		return;

	}
	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	toPlayer.Normalize();

	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; // 0 off the pitch
	RootComponent->SetWorldRotation(toPlayerRotation);

	/**FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 30.0f;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);*/
}

void AEnemigoTerrestre1::FireEnemigo()
{
	bCanFire = true;
	const FVector FireDirectionEnemigo = FVector(MovingTX, MovingTY, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotEnemigo(FireDirectionEnemigo);
}

void AEnemigoTerrestre1::FireShotEnemigo(FVector FireDirectionEnemigo)
{
	if (bCanFire == true)
	{
		if (FireDirectionEnemigo.SizeSquared() > 0.0f)
		{
			ANaveAereaJugador* avatar = Cast<ANaveAereaJugador>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
			if (!avatar)
			{
				return;

			}
			FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();

			const FRotator FireRotation = toPlayer.Rotation();
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEnemigoTerrestre1::ShotTimerExpired, FireRate);


		}
	}
}

void AEnemigoTerrestre1::ShotTimerExpired()
{
	bCanFire = true;
}
