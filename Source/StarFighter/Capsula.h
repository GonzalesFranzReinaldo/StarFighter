// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Capsula.generated.h"

UCLASS()
class STARFIGHTER_API ACapsula : public AActor
{
	GENERATED_BODY()

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

private:
	uint32 bCanCreateCapsule : 1;
	FTimerHandle TimerHandle_TimerExpired;

public:	
	// Sets default values for this actor's properties
	ACapsula();

	FTimerHandle MemberTimerHandle;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FString Nombre;
	FString TipoCapsula;
	FString TipoEfecto;
	FString TipoDuracion;
	float TiempoDuracion;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Generar();
	void Cargar();
	void Desplegar();
	void Destruir();

	FString GetNombre() { return Nombre; }

	float MovingX;
	float MovingY;

	void TimerExpired();
};
