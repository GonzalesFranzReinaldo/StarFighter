// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEscuadrillasCazaBuilder.h"
#include "Materials/Material.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
ANaveEscuadrillasCazaBuilder::ANaveEscuadrillasCazaBuilder()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialMesh(TEXT("MaterialInterface'/Game/TwinStick/Meshes/OrangeMaterial.OrangeMaterial'"));

	//static ConstructorHelpers::FObjectFinder<UMaterialInterface> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		FVector SpawnLocation = FVector(200.0f, -200.0f, 60.0f);
		FRotator SpawnRotator = FRotator(0.0f, -90.0f, 0.0f);

		NaveEnemigaEspacial = World->SpawnActor<ANaveEnemigaEspacial>(SpawnLocation, SpawnRotator);

		NaveEnemigaEspacial->GetShipMeshComponent()->SetMaterial(0, MaterialMesh.Object);

		NaveEnemigaEspacial->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
}

// Called when the game starts or when spawned
void ANaveEscuadrillasCazaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
	//NaveEnemigaEspacial = GetWorld()->SpawnActor<ANaveEnemigaEspacial>(ANaveEnemigaEspacial::StaticClass());
	//NaveEnemigaEspacial->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void ANaveEscuadrillasCazaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANaveEscuadrillasCazaBuilder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANaveEscuadrillasCazaBuilder::BuildVelocidad_Movimiento()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildVelocidad_Movimiento(): NaveEnemigaEspacial es NULL, asegurese de inicializar correctamente esta clase"));
	}
	NaveEnemigaEspacial->SetVelocidad_Movimiento("locidad Movimiento Caza");

}

void ANaveEscuadrillasCazaBuilder::BuildResistencia_Vida()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildResistencia_Vida(): NaveEnemigaEspacial es NULL, asegurese de inicializar correctamente esta clase"));
	}

	NaveEnemigaEspacial->SetResistencia_Vida("Resistencia Vida Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildSistemaRotacion()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaRotacion(): NaveEnemigaEspacial es NULL, asegurese de inicializar correctamente esta clase"));
	}

	NaveEnemigaEspacial->SetSistemaRotacion("Sistema Rotacion Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildSistemaEscudo()
{
	if (!NaveEnemigaEspacial)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaEscudo(): NaveEnemigaEspacial es NULL, asegurese de inicializar correctamente esta clase"));
	}

	NaveEnemigaEspacial->SetSistemaEscudo("Sistema Escudo Caza");
}

ANaveEnemigaEspacial* ANaveEscuadrillasCazaBuilder::GetNaveEnemigaEspacial()
{
	return NaveEnemigaEspacial;
}

