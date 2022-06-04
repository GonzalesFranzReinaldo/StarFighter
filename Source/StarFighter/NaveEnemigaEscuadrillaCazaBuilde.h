// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveEnemigaEscuadrillasBuilder.h"
#include "NaveEnemigaEscuadrillaCazaBuilde.generated.h"

UCLASS()
class STARFIGHTER_API ANaveEnemigaEscuadrillaCazaBuilde : public APawn, public INaveEnemigaEscuadrillasBuilder
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANaveEnemigaEscuadrillaCazaBuilde();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
private:
	// Propiedad donde le mando la clase Nave enemiga espacial para construirlo
	UPROPERTY(VisibleAnywhere, Category = "Nave Enemiga Esapacial Caza")
		class ANaveEnemigaEspacial* NaveEnemigaEspacial;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BuildVelocidad_Movimiento() override;
	virtual void BuildResistencia_Vida() override;
	virtual void BuildSistemaRotacion() override;
	virtual void BuildSistemaNivelDano() override;
	virtual void BuildSistemaEscudo() override;
	virtual class ANaveEnemigaEspacial* GetNaveEnemigaEspacial() override;
};
