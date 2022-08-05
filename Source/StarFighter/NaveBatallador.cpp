// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveBatallador.h"

// Sets default values
ANaveBatallador::ANaveBatallador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> NaveBatalladorMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	// Create the mesh component
	MeshNaveBatallador = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = MeshNaveBatallador;
	MeshNaveBatallador->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	MeshNaveBatallador->SetStaticMesh(NaveBatalladorMesh.Object);

	MoveSpeedNaveBatallador = 500.0f;

	MovingAX = 0.0f;
	MovingAY = 0.0f;

}

// Called when the game starts or when spawned
void ANaveBatallador::BeginPlay()
{
	Super::BeginPlay();

	////Enemies alert log
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("El NaveJugador quiere problemas asi que disparamos "));
	////Create the Brute Force Strategy and set it to the Battle Ship
	//StrategyDisparo = GetWorld() -> SpawnActor<AStrategyDisparo>(AStrategyDisparo::StaticClass());
	//NaveBatallador->AlterManeuvers(StrategyDisparo);
	////Engage with the current Strategy
	//NaveBatallador->Engage();

	////Enemies alert log
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("El NaveJugador se aleja, entonces nos desplazamos"));
	////Create the Divide Conquer Strategy and set it to the Battle Ship
	//StrategyDesplazar = GetWorld() -> SpawnActor<AStrategyDesplazar>(AStrategyDesplazar::StaticClass());
	//NaveBatallador->AlterManeuvers(StrategyDesplazar);
	////Engage with the current Strategy
	//NaveBatallador->Engage();

	////Enemies alert log
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("El NaveJugador activo el escudo, Nos Camuflamos"));
	////Create the Retreat Strategy and set it to the Battle Ship
	//StrategyCamuflage = GetWorld() -> SpawnActor<AStrategyCamuflage>(AStrategyCamuflage::StaticClass());
	//NaveBatallador->AlterManeuvers(StrategyCamuflage);
	////Engage with the current Strategy
	//NaveBatallador->Engage();
}

// Called every frame
void ANaveBatallador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	srand(time(NULL));

	MovingAX = rand() % 20 - 10;
	MovingAY = rand() % 20 - 10;

	MoveSpeedNaveBatallador = 20;

	const FVector MoveDirection = FVector(MovingAX, MovingAY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeedNaveBatallador * DeltaTime;

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

//void ANaveBatallador::AlterManeuvers(AActor* myStrategyNave)
//{
//	//Intente lanzar la estrategia pasada y configúrela en la actual
//	StrategyNave = Cast<IStrategyNave>(myStrategyNave);
//
//	//Log Error if the cast failed
//	if (!StrategyNave)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,TEXT("¡Elenco no válido! Consulte Registro de salida para obtener más detalles."));
//		UE_LOG(LogTemp, Error, TEXT("AlterManeuvers():¡El actor no es una estrategia de NaveBatallador! ¿Estás seguro de que el actor implementa esa interfaz? "));
//	}
//}

//void ANaveBatallador::Engage()
//{
//
//	//Log Error if the current Strategy is NULL
//	if (!StrategyNave) {
//		UE_LOG(LogTemp, Error, TEXT("Engage():EstrategiaNave es NULL, asegúrese de que esté inicializado."));
//		return;
//	}
//
//	//Execute the current Strategy Maneuver
//	StrategyNave->Maneuver();
//
//}

