// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveEnemigaBuilder.h"
#include "NaveEnemigaCazaBuilder.generated.h"

UCLASS()
class STARFIGHTER_API ANaveEnemigaCazaBuilder : public APawn, public INaveEnemigaBuilder
{
	GENERATED_BODY()

		// Esta clase sera un constructor de nave enemiga builder
public:
	// Sets default values for this pawn's properties
	ANaveEnemigaCazaBuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Nave Enemigo Caza")
		class ANavesEnemigas* NavesEnemigas;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BuildSistemaDefensa() override;
	virtual void BuildSistemaAtaque() override;
	virtual void BluidSistemaDesplazamiento() override;
	virtual void BluidSistemaCamuflaje() override;
	virtual class ANavesEnemigas* GetNavesEnemigas() override;

};
