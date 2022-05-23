// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MyInventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AMyInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos", meta = (AllowPrivateAccess = "true"))
		FString InventoryActorName;  // Crear un actor de inventario con tal nombre

public:
	// Sets default values for this actor's properties
	AMyInventoryActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	virtual void PickUp(); // Esta hace que va a recoger objetos
	virtual void PutDown(FTransform TargetLocation); // Funcion que va a soltar el lanzamiento

	// Segunda Parte

	FORCEINLINE FString GetInventoryActorName()const { return InventoryActorName; }
	FORCEINLINE void SerInventoryActorName(const FString _InventoryActorName) { InventoryActorName = _InventoryActorName; }

	float MovingX;
	float MovingY;

	/**UPROPERTY(Editanywhere)
		float SpeedScale;

	float RunningTime;*/
};
