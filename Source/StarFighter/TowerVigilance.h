// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PublisherObserver.h"
#include "TowerVigilance.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ATowerVigilance : public APublisherObserver
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATowerVigilance();

private:

	// The Enemy Ship Status
	FString ShipStatus;   //Estado de la Nave enemiga

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Called when the state of the enemy ship has changed 
	void StatusChanged();  //Funcion Cambio de Estado de la Nave

	//Set the state of the enemy ship  
	void SetStatusShipEnemi(FString myStatusShipEnemi);  //Devolver el estado de la nave enemiga

	//Return the state of the enemy ship 
	FORCEINLINE FString GetShipStatus() { return ShipStatus; };  //Debolver el  estado de la nave
};
