// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspacial.h"
#include "Proyectil.h"
#include "NaveAereaJugador.h"
#include "Kismet/GameplayStatics.h"

ANaveEnemigaEspacial::ANaveEnemigaEspacial()
{
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 2.0f;
	bCanFire = true;

	MoveSpeed = 150;
}

void ANaveEnemigaEspacial::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ANaveEnemigaEspacial::FireRifleShooter, 01.0f, true, 3.0f);
}

void ANaveEnemigaEspacial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * MoveSpeed;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

	FVector NewLocation2 = GetActorLocation();
	float DeltaForward = (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));
	NewLocation2.X += DeltaForward * MoveSpeed;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation2);

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

void ANaveEnemigaEspacial::FireRifleShooter()
{

	bCanFire = true;

	const FVector FireDirectionEnemigo = FVector(0.0f, RunningTime, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotEnemigo(FireDirectionEnemigo);

	//Print Fire log
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Nave Enemiga Espacial esta fusilando"));
}

void ANaveEnemigaEspacial::GetEntangle()
{
	//Call the parent Fight function and log a message
	Super::GetEntangle();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("La Nave Espacial obtenio una enmallada"));
}

void ANaveEnemigaEspacial::Die()
{
	//Call the parent Fight function and log a message
	Super::FireRifleShooter();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, TEXT("La Nave se destruye"));
}

void ANaveEnemigaEspacial::FireShotEnemigo(FVector FireDirectionEnemigo)
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
				World->SpawnActor<AProyectil>(SpawnLocation + FVector(50, -50, 0), FireRotation);
				World->SpawnActor<AProyectil>(SpawnLocation + FVector(-50, 50, 0), FireRotation);
				World->SpawnActor<AProyectil>(SpawnLocation + FVector(100, -100, 0), FireRotation);
				World->SpawnActor<AProyectil>(SpawnLocation + FVector(-100, 100, 0), FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemigaEspacial::ShotTimerExpired, FireRate);


		}
	}
}

void ANaveEnemigaEspacial::ShotTimerExpired()
{
	bCanFire = true;
}
