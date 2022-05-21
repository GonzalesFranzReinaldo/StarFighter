// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo3.h"
#include "Proyectil.h"
#include "NaveAereaJugador.h"
#include "Kismet/GameplayStatics.h"

AEnemigoAereo3::AEnemigoAereo3()
{
	MoveSpeed = 100.0f;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 2.0f;
	bCanFire = true;

	FireForwardValue = 0.0f;
	FireRightValue = 0.0f;

}

void AEnemigoAereo3::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AEnemigoAereo3::FireEnemigo, 01.0f, true, 5.0f);
}

void AEnemigoAereo3::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	MoveSpeed = 500;

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaSeconds) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * MoveSpeed;
	RunningTime += DeltaSeconds;
	SetActorLocation(NewLocation);

	FVector NewLocation2 = GetActorLocation();
	float DeltaForward = (FMath::Cos(RunningTime + DeltaSeconds) - FMath::Cos(RunningTime));
	NewLocation2.X += DeltaForward * MoveSpeed;
	RunningTime += DeltaSeconds;
	SetActorLocation(NewLocation2);

	const FVector MoveDirection = FVector(DeltaForward, DeltaHeight, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		/**if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}*/
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
}

void AEnemigoAereo3::FireEnemigo()
{
	bCanFire = true;
	const FVector FireDirectionEnemigo = FVector(FireForwardValue, FireRightValue, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotEnemigo(FireDirectionEnemigo);
}

void AEnemigoAereo3::FireShotEnemigo(FVector FireDirectionEnemigo)
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
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEnemigoAereo3::ShotTimerExpired, FireRate);


		}
	}
}

void AEnemigoAereo3::ShotTimerExpired()
{
	bCanFire = true;
}

