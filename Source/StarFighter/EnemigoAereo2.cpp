// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo2.h"
#include "Proyectil.h"
#include "NaveAereaJugador.h"
#include "Kismet/GameplayStatics.h"

AEnemigoAereo2::AEnemigoAereo2()
{
	MoveSpeed = 100.0f; // Esto es Para la velocidad
	MovingAX = 0.0f;
	MovingAY = 0.0f;

	GunOffset = FVector(90.f, 0.f, 0.f); //para la distancia de aparicion de la bala
	FireRate = 2.0f;
	bCanFire = true;

	//SpeedScale = 0.0f;
}

void AEnemigoAereo2::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AEnemigoAereo2::FireEnemigo, 01.0f, true, 2.0f);
}

void AEnemigoAereo2::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	srand(time(NULL));

	MovingAX = rand() % 20 - 10;
	MovingAY = rand() % 20 - 10;

	MoveSpeed = 20;

	const FVector MoveDirection = FVector(MovingAX, MovingAY, 0.0f);
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

	/**FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; // 0 off the pitch
	RootComponent->SetWorldRotation(toPlayerRotation);*/

	/**FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);*/

	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; // 0 off the pitch
	RootComponent->SetWorldRotation(toPlayerRotation);
}

void AEnemigoAereo2::FireEnemigo()
{
	UE_LOG(LogTemp, Warning, TEXT("Presionaste una tecla Proyectil"));// Sirve para ver el registro de salida

	bCanFire = true;
	const FVector FireDirectionEnemigo = FVector(MovingAX, MovingAY, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotEnemigo(FireDirectionEnemigo);
}

void AEnemigoAereo2::FireShotEnemigo(FVector FireDirection)
{
	if (bCanFire == true)
	{
		if (FireDirection.SizeSquared() > 0.0f)
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

				bCanFire = false;
				World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEnemigoAereo2::ShotTimerExpired, FireRate);
			}
		}
	}

}

void AEnemigoAereo2::ShotTimerExpired()
{
	bCanFire = true;
}
