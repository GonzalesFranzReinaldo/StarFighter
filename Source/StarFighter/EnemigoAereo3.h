// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaJugador.h"
#include "EnemigoAereo3.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoAereo3 : public ANaveAerea
{
	GENERATED_BODY()

private:

	AEnemigoAereo3();

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;

	float RunningTime;

	float FireForwardValue;
	float FireRightValue;

public:

	FTimerHandle MemberTimerHandle;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;//es como la distancia que aparecera la bala

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate; //propiedad que hara cuanto tardara en despareccere a bala

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float Speed;

	//UPROPERTY(Editanywhere)
		//float SpeedScale;

	// Sets default values for this actor's properties
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void FireEnemigo();
	void FireShotEnemigo(FVector FireDirectionEnemigo);
	void ShotTimerExpired();


};
