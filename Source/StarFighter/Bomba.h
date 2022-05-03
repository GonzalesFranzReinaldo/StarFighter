// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Bomba.generated.h"
//#include "GameFramework/Actor.h"

/**
 * 
 */

/*class USphereComponent;
class UParticleSystem;
class USoundCue;*/

UCLASS()
class STARFIGHTER_API ABomba : public AProyectil
{
	GENERATED_BODY()

		/** Sphere collision component */
	/*/UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	class USphereComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, Category = "FX")
	class UParticleSystem* ExplosionParticles;

	UPROPERTY(EditAnywhere, Category = "FX")
	class USoundCue* ExplosionSound;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	float Radius = 500.f;*/

public:
	ABomba();

	virtual void BeginPlay() override;

	/*/UFUNCTION()
	void OnDetonate();


	/** Function to handle the projectile hitting something */
	/*UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	/* Returns CollisionComp subobject */
	//FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComponent; }

	//float ADestructibleActor;
};
