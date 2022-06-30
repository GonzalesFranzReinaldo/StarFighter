// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaEnemigoNodriza.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveAereaEnemigoNodriza : public ANaveAerea
{
	GENERATED_BODY()

private:

	ANaveAereaEnemigoNodriza();

public:

	// Aqui declaramos la instancia de esta clase
	UPROPERTY()
		ANaveAereaEnemigoNodriza* Instance;

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;
	FTimerHandle MemberTimerHandle;
	FTimerHandle MemberTimerHandle1;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate; 

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float MoveSpeedNaveNodriza;

	float MovingTX;
	float MovingTY;


public:

	void FireEnemigo();
	void FireShot(FVector FireDirection);
	void ShotTimerExpired();
	
};
