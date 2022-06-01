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

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;

	//The mother enemy airship of this Actor
	// Aqui declaramos la instancia de esta clase
	UPROPERTY()
		ANaveAereaEnemigoNodriza* Instance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	FTimerHandle MemberTimerHandle;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate; 

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float SpeedScale;

public:

	void FireEnemigo();
	void FireShot(FVector FireDirection);
	void ShotTimerExpired();

	float MovingX;
	float MovingY;
	
};
