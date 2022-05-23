// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"
#include "Bomba.h"
#include "MyInventoryActor.h"
#include "MyInventoryComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
AProyectil::AProyectil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProyectil::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

	//Inventario
	ProyectilInventory = CreateDefaultSubobject<UMyInventoryComponent>("MyInventory");

	//Ship Info
	ProyectilInfo.Add("VelocidadProyectil", 0);


}

// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProyectil::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	Destroy();
}

void AProyectil::TakeItemP(AMyInventoryActor* MyInventoryItem)
{
	MyInventoryItem->PickUp();
	ProyectilInventory->AddToInventory(MyInventoryItem);
}

void AProyectil::DropItemP()
{
	if (ProyectilInventory->ShipInventoryActor.Num() == 0)
	{
		return;
	}
	AMyInventoryActor* Item = ProyectilInventory->ShipInventoryActor.Last();
	ProyectilInventory->RemoveFromInventory(Item);
	//should probably use scaled bounding box
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void AProyectil::ShowInventoryP()
{
	for (auto& Elem : ProyectilInfo) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));
	}
}

void AProyectil::TestP()
{
	TSet<int>EjemploSet;
	EjemploSet.Add(1);
	EjemploSet.Add(2);
	EjemploSet.Add(3);
	EjemploSet.Add(1);  //duplicate: won't be addeed
	EjemploSet.Add(1);  //duplicate: won't be addeed

	for (auto It = EjemploSet.CreateConstIterator(); It; ++It) {

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%d"), *It));
	}
}

void AProyectil::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation,
	FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AMyInventoryActor* ComeC = Cast<AMyInventoryActor>(Other);
	if (ComeC != nullptr) {

		for (auto& Elem : ProyectilInfo) {
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));
		}

		FString vp = "VelocidadProyectil";
		for (auto& pair : ProyectilInfo) {

			if (pair.Key == vp) {

				if (pair.Value > 0) {

					pair.Value = pair.Value - 1;
					ProjectileMovement->InitialSpeed = -1000.f;
					ProjectileMovement->MaxSpeed = -1000.f;
					break;
				}
			}
		}
	}
}