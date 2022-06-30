// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuatico1.h"
/*#include "NaveAereaJugador.h"
#include "Proyectil.h"
#include "NaveAereaJugador.h"
#include "StarFighterGameModeBase.h"
#include "NaveAereaEnemigoNodriza.h"
#include "Kismet/GameplayStatics.h"

AEnemigoAcuatico1::AEnemigoAcuatico1()
{
	//SpeedScale = 0.0f;
	MoveSpeedNaveAcuatica = 50.0f;

	MovingTX = 0.0f;
	MovingTY = 0.0f;

	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 2.0f;
	bCanFire = true;
}

void AEnemigoAcuatico1::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AEnemigoAcuatico1::FireEnemigo, 01.0f, true, 3.0f);
}

void AEnemigoAcuatico1::Tick(float DeltaSeconds)
{

	Super::Tick(DeltaSeconds);

	srand(time(NULL));

	MovingTX = rand() % 20 - 10;
	MovingTY = rand() % 20 - 10;

	//MoveSpeedNaveAcuatica = 20;

	const FVector MoveDirection = FVector(MovingTX, MovingTY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeedNaveAcuatica * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}

	// basic intel: move the monster towards the player
	ANaveAereaEnemigoNodriza* avatar = Cast<ANaveAereaEnemigoNodriza>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!avatar)
	{
		return;

	}
	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	toPlayer.Normalize();

	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; // 0 off the pitch
	RootComponent->SetWorldRotation(toPlayerRotation);

	//FVector NewLocation = GetActorLocation();
	//float DeltaHeight = (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));
	//NewLocation.X += DeltaHeight * SpeedScale;
	//RunningTime += DeltaTime;
	//SetActorLocation(NewLocation);
	
}

void AEnemigoAcuatico1::FireEnemigo()
{
	bCanFire = true;
	const FVector FireDirectionEnemigo = FVector(MovingTX, MovingTY, 0.0f).GetClampedToMaxSize(1.0f);
	
	FireShotEnemigo(FireDirectionEnemigo);
}

void AEnemigoAcuatico1::FireShotEnemigo(FVector FireDirectionEnemigo)
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
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEnemigoAcuatico1::ShotTimerExpired, FireRate);


		}
	}
}

void AEnemigoAcuatico1::ShotTimerExpired()
{
	bCanFire = true;
}*/
