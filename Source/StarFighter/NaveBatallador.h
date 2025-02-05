// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "StrategyNave.h"
//#include "StrategyDisparo.h"
//#include "StrategyDesplazar.h"
//#include "StrategyCamuflage.h"
#include "NaveBatallador.generated.h"

UCLASS()
class STARFIGHTER_API ANaveBatallador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANaveBatallador();

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* MeshNaveBatallador;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeedNaveBatallador;  //sera la velocidad usada por una Nave Enemiga

private:

	//La Estrategia acutual de la Nave Batallador
	//IStrategyNave* StrategyNave;

	//ANaveBatallador* NaveBatallador;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	float MovingAX;
	float MovingAY;

	// Cambiar la maniobra y establecer la variable "Estrategia Nave"
	//void AlterManeuvers(AActor* myStrategyNave);  // Funcion alternar maniobras

	// Comprometerse con la estrategia de la Nave Batallador
	//void Engage();  // Funcion Comprometerse

    //public:
	/*AStrategyDisparo* StrategyDisparo;
	AStrategyDesplazar* StrategyDesplazar;
	AStrategyCamuflage* StrategyCamuflage;*/
};
