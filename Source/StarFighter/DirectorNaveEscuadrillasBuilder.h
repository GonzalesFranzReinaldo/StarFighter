// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaEscuadrilla_01.h"
#include "NaveEnemigaEscuadrilla_02.h"
#include "NaveEnemigaEscuadrilla_03.h"
#include "NaveEscuadrillasBuilder.h"
#include "DirectorNaveEscuadrillasBuilder.generated.h"

UCLASS()
class STARFIGHTER_API ADirectorNaveEscuadrillasBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorNaveEscuadrillasBuilder();

private:
	INaveEscuadrillasBuilder* NaveEscuadrillasBuilder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Construir la Nave Enemiga Escuadrilla 01
	void ConstruirNaveEnemigaEscuadrilla_01();
    class ANaveEnemigaEscuadrilla_01* GetNaveEnemigaEscuadrilla_01();

	void SetNaveEscuadrillasBuilder(AActor* Builder);

	// Construir la Nave Enemiga Escuadrilla 02
	void ConstruirNaveEnemigaEscuadrilla_02();
	class ANaveEnemigaEscuadrilla_02* GetNaveEnemigaEscuadrilla_02();

	// Construir la Nave Enemiga Escuadrilla 03
	void ConstruirNaveEnemigaEscuadrilla_03();
	class ANaveEnemigaEscuadrilla_03* GetNaveEnemigaEscuadrilla_03();


};
