// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCazaBuilder.h"
#include "NavesEnemigas.h"

// Sets default values
ANaveEnemigaCazaBuilder::ANaveEnemigaCazaBuilder()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialMesh(TEXT("MaterialInterface'/Game/TwinStick/Meshes/OrangeMaterial.OrangeMaterial'"));

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		FVector SpawnLocation = FVector(200.0f, -200.0f, 60.0f);
		FRotator SpawnRotator = FRotator(0.0f, -90.0f, 0.0f);

		NavesEnemigas->GetShipMeshComponent()->SetMaterial(0, MaterialMesh.Object);
		NavesEnemigas = World->SpawnActor<ANavesEnemigas>(SpawnLocation, SpawnRotator);
		NavesEnemigas->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

		//NavesEnemigas->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		//NavesEnemigas = GetWorld()->SpawnActor<ANavesEnemigas>(ANavesEnemigas::StaticClass());
	}
}

// Called when the game starts or when spawned
void ANaveEnemigaCazaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemigaCazaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//NavesEnemigas = GetWorld()->SpawnActor<ANavesEnemigas>(ANavesEnemigas::StaticClass());
	//NavesEnemigas->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called to bind functionality to input
void ANaveEnemigaCazaBuilder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANaveEnemigaCazaBuilder::BuildSistemaDefensa()
{
	if (!NavesEnemigas)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaDefensa(): NaveEnemiga es null, inicialice correctamente la clase."));
		return;
	}

	NavesEnemigas->SetSistemaDefensa("Sistema Defensa Nave Enemiga Caza");
}

void ANaveEnemigaCazaBuilder::BuildSistemaAtaque()
{
	if (!NavesEnemigas)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaAtaque(): NaveEnemiga es null, inicialice correctamente la clase."));
		return;
	}

	NavesEnemigas->SetSistemaAtaque("Sistema Ataque Nave Enemiga Caza");
}

void ANaveEnemigaCazaBuilder::BluidSistemaDesplazamiento()
{
	if (!NavesEnemigas)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaDesplazamiento(): NaveEnemiga es null, inicialice correctamente la clase."));
		return;
	}

	NavesEnemigas->SetSistemaDesplazamiento("Sistema Desplazamiento Nave Enemiga Caza");
}

void ANaveEnemigaCazaBuilder::BluidSistemaCamuflaje()
{
	if (!NavesEnemigas)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildSistemaCamuflaje(): NaveEnemiga es null, inicialice correctamente la clase."));
		return;
	}

	NavesEnemigas->SetSistemaCamuflaje("Sistema Camuflaje Nave Enemiga Caza");
}

ANavesEnemigas* ANaveEnemigaCazaBuilder::GetNavesEnemigas()
{
	return NavesEnemigas;
}

