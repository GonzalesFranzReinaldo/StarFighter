// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrategyNave.h"
#include "StrategyDisparo.generated.h"

UCLASS()
class STARFIGHTER_API AStrategyDisparo : public AActor, public IStrategyNave
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrategyDisparo();

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;  // Es la distancia en la que aparece el Proyectil

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate;  //propiedad que hara cuanto tardara en desaparecer el proyectil.

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Ejecutar la Maniobra de esta Estrategia
	virtual void Maneuver() override; 

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;  // Tiempo en la que tarda
	FTimerHandle MemberTimerHandle;
	FTimerHandle MemberTimerHandle1;


	void FireNave();
	void FireShotNave(FVector FireDirection);
	void ShotTimerExpired();
};
