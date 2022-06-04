// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveEnemigaEspacial.h"
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
	UPROPERTY(VisibleAnywhere, Category = "Nave Enemigo Caza")
		class ANaveEnemigaEspacial* NaveEnemigaEspacial;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BuildVelocidad_Movimiento() override;
	virtual void BuildResistencia_Vida() override;
	virtual void BuildSistemaRotacion() override;
	virtual void BuildSistemaEscudo() override;

	virtual class ANaveEnemigaEspacial* GetNaveEnemigaEspacial() override;
};
