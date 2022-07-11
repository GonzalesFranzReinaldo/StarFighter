// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyCamuflage.h"
#include "DrawDebugHelpers.h"

// Sets default values
AStrategyCamuflage::AStrategyCamuflage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyCamuflage::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<FHitResult> OutHits;

	FVector ActorLocation = GetActorLocation();

	FCollisionShape MyColSphere = FCollisionShape::MakeSphere(350.f);

	DrawDebugSphere(GetWorld(), ActorLocation, MyColSphere.GetSphereRadius(), 100, FColor::Yellow, true);

	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, ActorLocation, ActorLocation, FQuat::Identity, ECC_WorldStatic, MyColSphere);

	if (isHit)
	{
		for (auto& Hit : OutHits)
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Camuflaje listo: %s"), *Hit.Actor->GetName()));
			}
		}
	}
}

// Called every frame
void AStrategyCamuflage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStrategyCamuflage::Maneuver()
{

	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("La NaveEnemigo tendra la Estrategia de Camuflarse"));

}

