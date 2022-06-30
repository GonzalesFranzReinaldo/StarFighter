// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "MyInventoryComponent.h"
#include "TowerVigilance.h"
#include "NaveEnemigo.h" // FreakyAllen
#include "NaveAereaJugador.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveAereaJugador : public ANaveAerea
{
	GENERATED_BODY()
	
	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos", meta = (AllowPrivateAccess = "true")) 
		FString NaveActorName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ANaveAereaJugador(); 

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Fire Esta funcion hace el Fuego
	void Fire();

	/* Fire a shot in the specified direction -  Disparo de Fuego */
	void FireShot(FVector FireDirection);

	/* Handler for the fire  timer expiry */
	void ShotTimerExpired();  // Esta funcion hace el temporizados del disparo

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;   // Propiedad que muestra el arma fuera de juego

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;   // creamos una propiedad cona FireRate velociad de fuego

	UPROPERTY()
		UMyInventoryComponent* CurrentInventory; // Crea un inventario actual en el Inventory Component

	UPROPERTY()
		TMap<FString, int32> ShipInfo; // TMap es vector sirve para guardar cantidad de objetos o atributos de las clases es una mapa de string

	UFUNCTION()
		void TakeItem(AMyInventoryActor* MyInventoryItem);

	UFUNCTION()
		void DropItem(); 

	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, 
			FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override; // Esta funcion me Notifica en golpe con un objeto

	UFUNCTION()
		void ShowInventory();

	UFUNCTION()
		void Test();

	UFUNCTION()
		void IncrementarVelocidad();

	UFUNCTION()
		void DecrementarVelocidad();

	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:

	/* Flag to control firing  */
	uint32 bCanFire : 1; // Puede disparar

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired; // Significa que va controlar el temporizador del disparo

	float FireForwardValue;
	float FireRightValue;

	float Vida;

	ATowerVigilance* TowerVigilance;

	ANaveEnemigo* NaveEnemigo1;
	ANaveEnemigo* NaveEnemigo2;
	ANaveEnemigo* NaveEnemigo3;

}; 