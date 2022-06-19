// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEspacial.h"
#include "DecoratorNaves.generated.h"

UCLASS()
class STARFIGHTER_API ADecoratorNaves : public AActor, public INaveEspacial
{
	GENERATED_BODY()
	
		UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ShipMeshComponent;

public:	
	// Sets default values for this actor's properties
	ADecoratorNaves();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	INaveEspacial* NaveEnemigaEspacial;

public:
	virtual void FireRifleShooter() override;  // Tirador de Fusiles
	virtual void GetEntangle() override;    // Obtener una Malla
	virtual void Die() override;           // Morir

	void SetNaveEspacial(INaveEspacial* _NaveEnemigaEspacial) { NaveEnemigaEspacial = _NaveEnemigaEspacial; }
	INaveEspacial* GetEnemy() { return NaveEnemigaEspacial; }
};
