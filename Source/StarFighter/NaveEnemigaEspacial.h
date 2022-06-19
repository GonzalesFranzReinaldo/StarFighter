// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DecoratorNaves.h"
#include "NaveEnemigaEspacial.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveEnemigaEspacial : public ADecoratorNaves
{
	GENERATED_BODY()
	
private:

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;

public:
	ANaveEnemigaEspacial();

	FTimerHandle MemberTimerHandle;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate;

	float RunningTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void FireRifleShooter();  // Tirador de Fusiles
	virtual void GetEntangle() override;    // Obtener una Malla
	virtual void Die() override;           // Morir

	void FireShotEnemigo(FVector FireDirectionEnemigo);
	void ShotTimerExpired();
};
