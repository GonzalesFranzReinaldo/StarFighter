// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaJugador.h"
#include "EnemigoAereo1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoAereo1 : public ANaveAerea
{
	GENERATED_BODY()

private:

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;

	float MovingX;
	float MovingY;

public:
	FTimerHandle MemberTimerHandle;

	AEnemigoAereo1();

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float Speed;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void FireEnemigo();
	void FireShotEnemigo(FVector FireDirectionEnemigo);
	void ShotTimerExpired();
};
