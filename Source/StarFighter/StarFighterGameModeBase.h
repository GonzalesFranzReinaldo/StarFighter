// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NaveEspacial.h"
#include "NaveAereaEnemigoNodriza.h"
#include "StarFighterGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class STARFIGHTER_API AStarFighterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AStarFighterGameModeBase();

	INaveEspacial* NaveEnemigaEspacial;

	void SpawnNaveEnemigaEspacial();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*template<typename T>
	T SpawnNave();*/

private:

	//singleton
	UPROPERTY()
		class ANaveAereaEnemigoNodriza* NaveNodriza;

protected:

	virtual void BeginPlay() override;

	float ejeX; //daremos valores aleatorios 
	float ejeY; //daremos valores aleatorios 

	float PejeX;
	float PejeY;
	float contador;

	FTimerHandle AcuaticaTimerHandle;
	FTimerHandle AcuaticaTimerHandle1;

public:

	static int contadorBalas;
	void SpawnNave();

/*private:
	UPROPERTY(VisibleAnywhere, Category = "Implementar Caza builder")
		class ANaveEscuadrillasCazaBuilder* NaveEscuadrillasCazaBuilder;

	UPROPERTY(VisibleAnywhere, Category = "Implementar Director builder")
		class ADirectorNaveEscuadrillasBuilder* DirectorNaveEscuadrillasBuilder;*/

};

//template<typename T>
//inline T AStarFighterGameModeBase::SpawnNave()
//{
//	return GetWorld()->SpawnActor<T>(FVector::ZeroVector, FRotator::ZeroRotator);
//}
