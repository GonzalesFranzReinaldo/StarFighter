// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventoryComponent.h"

// Sets default values for this component's properties
UMyInventoryComponent::UMyInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UMyInventoryComponent::AddToInventory(AMyInventoryActor* ActorToAdd)
{
	return ShipInventoryActor.Add(ActorToAdd);
}

void UMyInventoryComponent::RemoveFromInventory(AMyInventoryActor* ActorToRemove)
{
	ShipInventoryActor.Remove(ActorToRemove);
}

