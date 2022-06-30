// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerVigilance.h"

ATowerVigilance::ATowerVigilance()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATowerVigilance::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATowerVigilance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATowerVigilance::StatusChanged()
{
	//Cuando el estado ha cambiado, la torre de vigilancia notifica a todos los suscriptores de el estado de la nave enemiga a cambiado
	NotifySubscribersShip();
}

void ATowerVigilance::SetStatusShipEnemi(FString myStatusShipEnemi)
{
	// Establecer el estado de la nave enemiga
	ShipStatus = myStatusShipEnemi;

	StatusChanged();
}
