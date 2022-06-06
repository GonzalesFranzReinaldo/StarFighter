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

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		FVector SpawnLocation = FVector(200.0f, -200.0f, 60.0f); 
		FRotator SpawnRotator = FRotator(0.0f, -90.0f, 0.0f);

		NaveEnemigaEscuadrilla_01 = World->SpawnActor<ANaveEnemigaEscuadrilla_01>(SpawnLocation, SpawnRotator);
		NaveEnemigaEscuadrilla_01->GetShipMeshComponent()->SetMaterial(0, MaterialMesh.Object);
		NaveEnemigaEscuadrilla_01->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

		NaveEnemigaEscuadrilla_02 = World->SpawnActor<ANaveEnemigaEscuadrilla_02>(SpawnLocation, SpawnRotator);
		NaveEnemigaEscuadrilla_02->GetShipMeshComponent()->SetMaterial(0, MaterialMesh.Object);
		NaveEnemigaEscuadrilla_02->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

		NaveEnemigaEscuadrilla_03 = World->SpawnActor<ANaveEnemigaEscuadrilla_03>(SpawnLocation, SpawnRotator);
		NaveEnemigaEscuadrilla_03->GetShipMeshComponent()->SetMaterial(0, MaterialMesh.Object);
		NaveEnemigaEscuadrilla_03->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

		MoveSpeed = 100.0f;
		MovingTX = 0.0f;
		MovingTY = 0.0f;

	}

	/*auto MaterialMesh = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("MaterialInterface'/Game/TwinStick/Meshes/OrangeMaterial.OrangeMaterial'"));
	
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		FVector SpawnLocation = FVector(200.0f, -200.0f, 60.0f);
		FRotator SpawnRotator = FRotator(0.0f, -90.0f, 0.0f);

		NaveEnemigaEscuadrilla_01 = World->SpawnActor<ANaveEnemigaEscuadrilla_01>(SpawnLocation, SpawnRotator);
		NaveEnemigaEscuadrilla_01->GetShipMeshComponent()->SetMaterial(1, MaterialMesh.Object);
		NaveEnemigaEscuadrilla_01->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	}*/
}

// Called when the game starts or when spawned
void ANaveEscuadrillasCazaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
	//NaveEnemigaEscuadrilla_01 = GetWorld()->SpawnActor<ANaveEnemigaEscuadrilla_01>(ANaveEnemigaEscuadrilla_01::StaticClass());
	//NaveEnemigaEscuadrilla_01->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void ANaveEscuadrillasCazaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	srand(time(NULL));

	MovingTX = rand() % 20 - 10;
	MovingTY = rand() % 20 - 10;

	MoveSpeed = 1000;

	const FVector MoveDirection = FVector(MovingTX, MovingTY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaTime;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}

}

// Called to bind functionality to input
void ANaveEscuadrillasCazaBuilder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANaveEscuadrillasCazaBuilder::BuildVelocidad_Movimiento()
{
	if (!NaveEnemigaEscuadrilla_01)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildVelocidad_Movimiento(): NaveEnemigaEscuadrilla_01 es NULL, inicializar correctamente esta clase"));
	}
	NaveEnemigaEscuadrilla_01->SetVelocidad_Movimiento("locidad Movimiento Caza");

}

void ANaveEscuadrillasCazaBuilder::BuildResistencia_Vida()
{
	if (!NaveEnemigaEscuadrilla_01)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildResistencia_Vida(): NaveEnemigaEscuadrilla_01 es NULL, inicializar correctamente esta clase"));
	}

	NaveEnemigaEscuadrilla_01->SetResistencia_Vida("Resistencia Vida Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildSistemaRotacion()
{
	if (!NaveEnemigaEscuadrilla_01)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaRotacion(): NaveEnemigaEscuadrilla_01 es NULL, inicializar correctamente esta clase"));
	}

	NaveEnemigaEscuadrilla_01->SetSistemaRotacion("Sistema Rotacion Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildSistemaEscudo()
{
	if (!NaveEnemigaEscuadrilla_01)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaEscudo(): NaveEnemigaEscuadrilla_01 es NULL, inicializar correctamente esta clase"));
	}

	NaveEnemigaEscuadrilla_01->SetSistemaEscudo("Sistema Escudo Caza");
}

ANaveEnemigaEscuadrilla_01* ANaveEscuadrillasCazaBuilder::GetNaveEnemigaEscuadrilla_01()
{
	return NaveEnemigaEscuadrilla_01;
}

void ANaveEscuadrillasCazaBuilder::BuildNivelInvasion()
{
	if (!NaveEnemigaEscuadrilla_02)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildNivelInvasion(): NaveEnemigaEscuadrilla_02 es NULL, inicializar correctamente esta clase"));
	}
	NaveEnemigaEscuadrilla_02->SetNivelInvasion("nivel invasion Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildNivelDisparo()
{
	if (!NaveEnemigaEscuadrilla_02)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildNivelDisparo(): NaveEnemigaEscuadrilla_02 es NULL, inicializar correctamente esta clase"));
	}
	NaveEnemigaEscuadrilla_02->SetNivelDisparo("nivel diasparo Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildSistemaGravedad()
{
	if (!NaveEnemigaEscuadrilla_02)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaVelocidad(): NaveEnemigaEscuadrilla_02 es NULL, inicializar correctamente esta clase"));
	}
	NaveEnemigaEscuadrilla_02->SetSistemaGravedad("sistema gravedad Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildSistemaMuniciones()
{
	if (!NaveEnemigaEscuadrilla_02)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaMuniciones(): NaveEnemigaEscuadrilla_02 es NULL, inicializar correctamente esta clase"));
	}
	NaveEnemigaEscuadrilla_02->SetSistemaMuniciones("sistema municiones Caza");
}

ANaveEnemigaEscuadrilla_02* ANaveEscuadrillasCazaBuilder::GetNaveEnemigaEscuadrilla_02()
{
	return NaveEnemigaEscuadrilla_02;
}

void ANaveEscuadrillasCazaBuilder::BuildBombardeo()
{
	if (!NaveEnemigaEscuadrilla_03)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildBombardeo(): NaveEnemigaEscuadrilla_03 es NULL, inicializar correctamente esta clase"));
	}
	NaveEnemigaEscuadrilla_03->SetBombardeo("Bombardeo Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildDesaparecer()
{
	if (!NaveEnemigaEscuadrilla_03)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildDesaparecer(): NaveEnemigaEscuadrilla_03 es NULL, inicializar correctamente esta clase"));
	}
	NaveEnemigaEscuadrilla_03->SetDesaparecer("Desaparecer Caza");
}

void ANaveEscuadrillasCazaBuilder::BuildSistemaCrecer()
{
	if (!NaveEnemigaEscuadrilla_03)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildSistemaCrecer(): NaveEnemigaEscuadrilla_03 es NULL, inicializar correctamente esta clase"));
	}
	NaveEnemigaEscuadrilla_03->SetSistemaCrecer("Sistema Crecer Caza");
}

ANaveEnemigaEscuadrilla_03* ANaveEscuadrillasCazaBuilder::GetNaveEnemigaEscuadrilla_03()
{
	return NaveEnemigaEscuadrilla_03;
}

