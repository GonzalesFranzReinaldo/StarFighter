// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryActor.h"
#include "NaveAereaJugador.h"

AMyInventoryActor::AMyInventoryActor():Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);

	MoveSpeed = 100.0f; // Esto es Para la velocidad
	MovingX = 0.0f;
	MovingY = 0.0f;

	//SpeedScale = 0.0f;
}

void AMyInventoryActor::BeginPlay()
{
	Super::BeginPlay();

}

void AMyInventoryActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	srand(time(NULL));

	MovingX = rand() % 20 - 10;
	MovingY = rand() % 20 - 10;

	MoveSpeed = 50;

	const FVector MoveDirection = FVector(MovingX, MovingY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		
		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}

	/**FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaSeconds) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * SpeedScale;
	RunningTime += DeltaSeconds;
	SetActorLocation(NewLocation);*/
}

void AMyInventoryActor::PickUp()  // Esto hace que recoge  a los objetos
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AMyInventoryActor::PutDown(FTransform TargetLocation)  // Esto hace que va a soltar los objetos
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());
}
