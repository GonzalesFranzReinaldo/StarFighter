// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Singleton.generated.h"

UCLASS()
class STARFIGHTER_API ASingleton : public AActor
{
	GENERATED_BODY()

private:
	// Sets default values for this actor's properties
	ASingleton();

	// En esta propiedad declaramos la clase nave nodriza para implementar en el singleton
	//The mother enemy airship of this Actor
	UPROPERTY()
		class ANaveAereaEnemigoNodriza* NaveAereaEnemigoNodriza; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
