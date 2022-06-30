// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SubscriberObserver.h"
#include "ShipMorph.h"
#include "NaveEnemigo.generated.h"

class ATowerVigilance;

UCLASS()
class STARFIGHTER_API ANaveEnemigo : public AActor, public ISubscriberObserver, public IShipMorph
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ANaveEnemigo();

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ShipMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeedNaveEnemigo;  //sera la velocidad usada por una Nave Enemiga

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;  // Es la distancia en la que aparece el Proyectil

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate;  //propiedad que hara cuanto tardara en desaparecer el proyectil.

	float MovingAX;
	float MovingAY;

private:
	//The Clock Tower of this Subscriber
	UPROPERTY()
		ATowerVigilance* TowerVigilance;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;  // Tiempo en la que tarda
	FTimerHandle MemberTimerHandle;
	FTimerHandle MemberTimerHandle1;


	void FireNaveEnemigo();
	void FireShotNaveEnemigo(FVector FireDirectionEnemigo);
	void ShotTimerExpired();

public:

	// Llamado cuando este Suscriptor es destruido, lo dará de baja del Torre de Vigilancia
	virtual void Destroyed() override;

	//Called when the Plublisher changed its state, it will execute this Subscriber routine
	virtual void Update(class APublisherObserver* PublisherObserver) override;

	//Execute this Subscriber routine
	virtual void ShipMorph();  // Funcion de tranformacion de la nave

	//Set the Tower Vigilance of this Subscriber
	void SetTowerVigilance(ATowerVigilance* myTowerVigilance);
};
