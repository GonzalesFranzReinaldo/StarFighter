// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveTerrestre.h"
#include "NaveAereaJugador.h"
#include "EnemigoTerrestre1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoTerrestre1 : public ANaveTerrestre
{
	GENERATED_BODY()

private:

	AEnemigoTerrestre1();
	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;

public:

	FTimerHandle MemberTimerHandle;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate; 
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float Speed;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float Deltaseconds) override;

	void FireEnemigo();
	void FireShotEnemigo(FVector FireDirectionEnemigo);
	void ShotTimerExpired();


	//float RunningTime;


};
