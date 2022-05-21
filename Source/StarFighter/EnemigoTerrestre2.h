// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveTerrestre.h"
#include "NaveAereaJugador.h"
#include "EnemigoTerrestre2.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoTerrestre2 : public ANaveTerrestre
{
	GENERATED_BODY()

private:
	
	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;
	
public:

	FTimerHandle MemberTimerHandle;

	// Sets default values for this actors properties
	AEnemigoTerrestre2();

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
