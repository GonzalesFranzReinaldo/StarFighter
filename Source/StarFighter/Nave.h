// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Nave.generated.h"


UCLASS()
class STARFIGHTER_API ANave : public APawn
{
	GENERATED_BODY()
	// N: 2	 UstaticMeshComponent es para todos los objetos que van a heredar de la clase padre  
	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ShipMeshComponent;

public:
	// Sets default values for this pawn's properties
	ANave();
	// N:3 Para moverse a una velocidad donde todos heredan del padre
	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		class USoundBase* FireSound;

	// N:4 Energia donde todos los objetos deben tener que van a heredar
	/* The energy ship */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float Energy;

	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireBinding;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// N:6 esto es un metodo donde le que le devuelva la malla  

	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return ShipMeshComponent; }

	FORCEINLINE void SetShipMeshComponent(class UStaticMeshComponent* _ShipMeshComponent) { ShipMeshComponent = _ShipMeshComponent; }
};
