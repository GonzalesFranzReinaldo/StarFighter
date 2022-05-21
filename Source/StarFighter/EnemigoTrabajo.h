// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "EnemigoTrabajo.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoTrabajo : public ANaveAerea
{
	GENERATED_BODY()

private:
	uint32 bCanFire : 1;

public:

	AEnemigoTrabajo();

	FTimerHandle TimerHandle_ShotTimerExpired;
	FTimerHandle MemberTimerHandle;

	virtual void BeginPlay() override;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float Speed;

	void Tick(float DeltaSeconds);

	void FireEnemigo();
	void FireNaveEnemigo(FVector FireDirectionEnemigo);
	void ShotTimerExpired();

	float MovingTX;
	float MovingTY;
	
};
