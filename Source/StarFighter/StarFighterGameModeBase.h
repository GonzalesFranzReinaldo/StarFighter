// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StarFighterGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class STARFIGHTER_API AStarFighterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	AStarFighterGameModeBase();

	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Implementar builder")
		class ANaveEscuadrillasCazaBuilder* NaveEscuadrillasCazaBuilder;

	UPROPERTY(VisibleAnywhere, Category = "Implementar builder")
		class ADirectorNaveEscuadrillasBuilder* Director;
};
