// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"

// Sets default values
ACapsula::ACapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	TiempoDuracion = 0.0f;

	MoveSpeed = 1500.0f;
	MovingX = 0.0f;
	MovingY = 0.0f;
}

// Called when the game starts or when spawned
void ACapsula::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ACapsula::Generar, 10.0f, true, 5.0f);
}

// Called every frame
void ACapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	srand(time(NULL));

	MovingX = rand() % 20 - 10;
	MovingY = rand() % 20 - 10;

	MoveSpeed = 50;


	const FVector MoveDirection = FVector(MovingX, MovingY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaTime;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}

void ACapsula::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Generando las capsulas %s"), *GetNombre()));
}

void ACapsula::Cargar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se estan cargando las capsulas")));
}

void ACapsula::Desplegar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Se estan desplegando las capsulas")));
}

void ACapsula::Destruir()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Las capsulas se estan destruyendo")));
}

void ACapsula::TimerExpired()
{
	bCanCreateCapsule = true;
}

