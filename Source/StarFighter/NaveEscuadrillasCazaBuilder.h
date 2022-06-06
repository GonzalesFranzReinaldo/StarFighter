// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveEnemigaEscuadrilla_01.h"
#include "NaveEnemigaEscuadrilla_02.h"
#include "NaveEnemigaEscuadrilla_03.h"
#include "NaveEscuadrillasBuilder.h"
#include "NaveEscuadrillasCazaBuilder.generated.h"

UCLASS()
class STARFIGHTER_API ANaveEscuadrillasCazaBuilder : public APawn, public INaveEscuadrillasBuilder
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANaveEscuadrillasCazaBuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Nave Escuadrilla Caza 1")
		class ANaveEnemigaEscuadrilla_01* NaveEnemigaEscuadrilla_01;

	UPROPERTY(VisibleAnywhere, Category = "Nave Escuadrilla Caza 2")
		class ANaveEnemigaEscuadrilla_02* NaveEnemigaEscuadrilla_02;

	UPROPERTY(VisibleAnywhere, Category = "Nave Escuadrilla Caza 3")
		class ANaveEnemigaEscuadrilla_03* NaveEnemigaEscuadrilla_03;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float MoveSpeed;

	float MovingTX;
	float MovingTY;

public:
	// Nave Enemiga Escuadrilla 01
	virtual void BuildVelocidad_Movimiento() override;
	virtual void BuildResistencia_Vida() override;
	virtual void BuildSistemaRotacion() override;
	virtual void BuildSistemaEscudo() override;

	virtual class ANaveEnemigaEscuadrilla_01* GetNaveEnemigaEscuadrilla_01() override;

	// Nave Enemiga Escuadrilla 01
	virtual void BuildNivelInvasion() override;
	virtual void BuildNivelDisparo() override;
	virtual void BuildSistemaGravedad() override;
	virtual void BuildSistemaMuniciones() override;

	virtual class ANaveEnemigaEscuadrilla_02* GetNaveEnemigaEscuadrilla_02() override;

	// Nave Enemiga Escuadrilla 03
	virtual void BuildBombardeo() override;
	virtual void BuildDesaparecer() override;
	virtual void BuildSistemaCrecer() override;

	virtual class ANaveEnemigaEscuadrilla_03* GetNaveEnemigaEscuadrilla_03() override;

};
