// Fill out your copyright notice in the Description page of Project Settings.


#include "Nave.h"
#include "Materials/Material.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"


const FName ANave::MoveForwardBinding("MoveForward");
const FName ANave::MoveRightBinding("MoveRight");
const FName ANave::FireBinding("Fire");

// Sets default values
ANave::ANave()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//N:9 esta me crea un objeto de tip mesh para endozar directo ala malla saca su direccion
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	// N:12 creamos la velocidad de movimiento y las energias en el padre que va a heredar sus hijas
	// Movement
	MoveSpeed = 1000.0f;

	//Energy
	Energy = 100.0f;

}

// Called when the game starts or when spawned
void ANave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANave::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

