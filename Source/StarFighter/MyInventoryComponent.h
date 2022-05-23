// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyInventoryActor.h"
#include "MyInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARFIGHTER_API UMyInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override; // Componente de marca

	UPROPERTY()
		TArray<AMyInventoryActor*> ShipInventoryActor; // Esta Array es la clave de todo donde va a almacenar todos los objetos o componentes en el juego

	UFUNCTION()
		int32 AddToInventory(AMyInventoryActor* ActorToAdd); // Va a añadir al actor

	UFUNCTION()
		void RemoveFromInventory(AMyInventoryActor* ActorToRemove); // Va a quitar o remover al actor
};
