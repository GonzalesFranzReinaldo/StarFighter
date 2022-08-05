// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigo.h"
#include "PublisherObserver.h"
#include "TowerVigilance.h"
#include "Proyectil.h"
#include "Kismet/GameplayStatics.h"
#include "NaveAereaJugador.h"


// Sets default values
ANaveEnemigo::ANaveEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	MoveSpeedNaveEnemigo = 1.0f;

	GunOffset = FVector(90.f, 0.f, 0.f);  //para la distancia de aparicion de la bala.
	FireRate = 2.0f;
	bCanFire = true;

	MovingAX = 0.0f;
	MovingAY = 0.0f;
}

// Called when the game starts or when spawned
void ANaveEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
	//GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ANaveEnemigo::FireEnemigo, 01.0f, true, 3.0f);
}

// Called every frame
void ANaveEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ANaveEnemigo::Destroyed()
{
	Super::Destroyed();

	//Log Error if its Tower Vigilance is NULL
	if (!TowerVigilance) {
		UE_LOG(LogTemp, Error, TEXT("Destroyed (): Tower Vigilance es NULL, asegúrese de que esté inicializado."));
		return;
	}
	//Unsubscribe from the Clock Tower if it's destroyed
	TowerVigilance->SubscribeShip(this);
}

void ANaveEnemigo::Update(APublisherObserver* PublisherObserver)
{
	//Execute the routine
	ShipMorph();  //transformar

}

void ANaveEnemigo::ShipMorph()
{
	//Log Error if its Tower Vigilance is NULL
	if (!TowerVigilance) {
		UE_LOG(LogTemp, Error, TEXT("ShipMorph (): Tower Vigilance es NULL, asegúrese de que esté inicializado."));
		return;
	}

	//Get the current time of the Clock Tower
	FString ShipStatus = TowerVigilance->GetShipStatus();
	if (!ShipStatus.Compare("NaveAereaJugador en Movimiento"))
	{
		//Execute the Enemigo Estatico routine
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("%s -> Las Naves Enemigas se Mueven"), *ShipStatus));

		srand(time(NULL));

		MovingAX = rand() % 18 - 10;
		MovingAY = rand() % 18 - 10;

		const FVector MoveDirection = FVector(MovingAX, MovingAY, 0.0f);
		const FVector Movement = MoveDirection * MoveSpeedNaveEnemigo;

		if (Movement.SizeSquared() > 0.0f)
		{
			const FRotator NewRotation = Movement.Rotation();

			FHitResult Hit(1.0f);
			RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		}

		// basic intel: move the monster towards the player
		/*ANaveAereaJugador* avatar = Cast<ANaveAereaJugador>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		if (!avatar)
		{
			return;

		}
		FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
		toPlayer.Normalize();*/

	}
	else if (!ShipStatus.Compare("NaveAereaJugador Atacando"))
	{
		//Execute the Enemigo en Movimiento routine
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s -> Las Naves Enemigas Disparan"), *ShipStatus));

		FireNaveEnemigo();

	}
	else if (!ShipStatus.Compare("NaveAereaJugador Estatico"))
	{
		//Execute the Enemigo en Movimiento routine
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("%s -> Las Naves Enemigas no se mueven"),*ShipStatus));

	}
}

void ANaveEnemigo::SetTowerVigilance(ATowerVigilance* myTowerVigilance)
{
	//Log Error if the passed Tower Vigilance is NULL
	if (!myTowerVigilance) {
		UE_LOG(LogTemp, Error, TEXT("TowerVigilance(): myTowerVigilance es NULL, asegúrese de que esté inicializado."));
		return;
	}

	//Set the Clock Tower and Subscribe to that
	TowerVigilance = myTowerVigilance;
	TowerVigilance->SubscribeShip(this);
}

void ANaveEnemigo::FireNaveEnemigo()
{
	
	bCanFire = true;

	const FVector FireDirectionEnemigo = FVector(MovingAX, MovingAY, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotNaveEnemigo(FireDirectionEnemigo);

}

void ANaveEnemigo::FireShotNaveEnemigo(FVector FireDirectionEnemigo)
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

				bCanFire = false;
				World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveEnemigo::ShotTimerExpired, FireRate);
			}
		}

	}
}

void ANaveEnemigo::ShotTimerExpired()
{
	bCanFire = true;
}
