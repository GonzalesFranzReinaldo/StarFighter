// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAcuatico.h"
#include "NaveAereaJugador.h"
#include "EnemigoAcuatico1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoAcuatico1 : public ANaveAcuatico
{
	GENERATED_BODY()

private:
	AEnemigoAcuatico1();

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;
	
public:

	FTimerHandle MemberTimerHandle;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;// ES para ver en que distancia aparece el Proyectil

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate; //propiedad que hace que cuanto tiempo desaparece el proyectil

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float Speed;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void FireEnemigo();
	void FireShotEnemigo(FVector FireDirectionEnemigo);
	void ShotTimerExpired();

	/**UPROPERTY(Editanywhere)
		float SpeedScale;

	float RunningTime;*/
};
