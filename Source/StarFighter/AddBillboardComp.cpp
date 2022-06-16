// Fill out your copyright notice in the Description page of Project Settings.


#include "AddBillboardComp.h"
#include "Proyectil.h"
#include "NaveAereaJugador.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BillboardComponent.h"

// Sets default values
AAddBillboardComp::AAddBillboardComp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SoundWave'/Game/TwinStick/Audio/TwinStickFire.TwinStickFire'

	MyBillboardComp = CreateDefaultSubobject<UBillboardComponent>(TEXT("My Billboard"));
	MyBillboardComp->SetHiddenInGame(false, true);
	RootComponent = MyBillboardComp;

	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 2.0f;
	bCanFire = true;

	/*MovingTX = 0.0f;
	MovingTY = 0.0f;*/
}

// Called when the game starts or when spawned
void AAddBillboardComp::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AAddBillboardComp::FireEnemigo, 01.0f, true, 3.0f);
}

// Called every frame
void AAddBillboardComp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 100.0f;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

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

void AAddBillboardComp::FireEnemigo()
{

	bCanFire = true;

	const FVector FireDirectionEnemigo = FVector(0.0f, RunningTime, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotEnemigo(FireDirectionEnemigo);

	//Print Fire log
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Nuesta Cartelera esta disparando"));
}

void AAddBillboardComp::FireShotEnemigo(FVector FireDirectionEnemigo)
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
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AAddBillboardComp::ShotTimerExpired, FireRate);


		}
	}
}

void AAddBillboardComp::ShotTimerExpired()
{
	bCanFire = true;
}

