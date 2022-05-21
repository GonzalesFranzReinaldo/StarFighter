// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaJugador.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveAereaJugador : public ANaveAerea
{
	GENERATED_BODY()
	// N: 1 La Camara solo se chata en La nave jugador
	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
// N: 5  son metodos para que la nave vea la manera de manejarse 
public:
	ANaveAereaJugador(); // constructor y creamos su clase cpp

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;


private:

	/* Float to control firing */
	uint32 bCanFire : 1;

	/*  Handle for efficient management of ShotTimeExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	float FireForwardValue;
	float FireRightValue;


public:
	//N:14 declaramos la funcion de las entradas del setupPlayerInputComponent  n  
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 

	// Fire 
	void Fire();

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);

	/* Handler for the fire  timer expiry */
	void ShotTimerExpired();

	//N:7 estos metodos me dicen que van a devolver las camaras al jugador
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
