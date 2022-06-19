// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoratorNaves.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "DrawDebugHelpers.h"

// Sets default values
ADecoratorNaves::ADecoratorNaves()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

}

// Called when the game starts or when spawned
void ADecoratorNaves::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<FHitResult> OutHits;

	FVector ActorLocation = GetActorLocation();

	FCollisionShape MyColSphere = FCollisionShape::MakeSphere(350.f);

	DrawDebugSphere(GetWorld(), ActorLocation, MyColSphere.GetSphereRadius(), 100, FColor::Purple, true);

	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, ActorLocation, ActorLocation, FQuat::Identity, ECC_WorldStatic, MyColSphere);

	if (isHit)
	{
		for (auto& Hit : OutHits)
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Hit Result: %s"), *Hit.Actor->GetName()));
			}
		}
	}
}

// Called every frame
void ADecoratorNaves::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecoratorNaves::FireRifleShooter()
{
	this->NaveEnemigaEspacial->FireRifleShooter();
}

void ADecoratorNaves::GetEntangle()
{
	this->NaveEnemigaEspacial->GetEntangle();
}

void ADecoratorNaves::Die()
{
	this->NaveEnemigaEspacial->Die();
}

