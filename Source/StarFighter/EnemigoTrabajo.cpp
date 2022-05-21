// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTrabajo.h"
#include "Proyectil.h"
#include "Kismet/GameplayStatics.h"

AEnemigoTrabajo::AEnemigoTrabajo()
{
	MoveSpeed = 100.0f;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 2.0f;
	bCanFire = true;

	MovingTX = 0.0f;
	MovingTY = 0.0f;

}

void AEnemigoTrabajo::BeginPlay()
{
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AEnemigoTrabajo::FireEnemigo, 10.0f, true, 5.0f);

}

void AEnemigoTrabajo::FireEnemigo()
{
	bCanFire = true;
	const FVector FireDirectionEnemigo = FVector(MovingTX, MovingTY, 0.0f).GetClampedToMaxSize(1.0f);

	FireNaveEnemigo(FireDirectionEnemigo);
}

void AEnemigoTrabajo::FireNaveEnemigo(FVector FireDirectionEnemigo)
{
	if (bCanFire == true)
	{
		if (FireDirectionEnemigo.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirectionEnemigo.Rotation();
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEnemigoTrabajo::ShotTimerExpired, FireRate);

		}
	}
}

void AEnemigoTrabajo::ShotTimerExpired()
{
	bCanFire = true;
}

void AEnemigoTrabajo::Tick(float DeltaSeconds)
{
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
}
