// Fill out your copyright notice in the Description page of Project Settings.


#include "AddBillboardCompAdapter.h"
#include "AddBillboardComp.h"

// Sets default values
AAddBillboardCompAdapter::AAddBillboardCompAdapter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAddBillboardCompAdapter::BeginPlay()
{
	Super::BeginPlay();
	
	ShotEnemy = GetWorld()->SpawnActor<AAddBillboardComp>(AAddBillboardComp::StaticClass());
}

// Called every frame
void AAddBillboardCompAdapter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAddBillboardCompAdapter::Shooting()
{
	if (!ShotEnemy) {
		UE_LOG(LogTemp, Error, TEXT("Shooting(): Cartelera is	NULL, make sure it's initialized."));
		return;
	}
	
	//Call the Fire function
	ShotEnemy->FireEnemigo();
}

void AAddBillboardCompAdapter::Bombing()
{
	if (!BombEnemy) {
		UE_LOG(LogTemp, Error, TEXT("Bombing(): Cartelera is	NULL, make sure it's initialized."));
		return;
	}

	//Call the Fire function
	BombEnemy->FireEnemigo();
}

