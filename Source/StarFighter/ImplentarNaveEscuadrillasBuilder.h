// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImplentarNaveEscuadrillasBuilder.generated.h"

UCLASS()
class STARFIGHTER_API AImplentarNaveEscuadrillasBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AImplentarNaveEscuadrillasBuilder();

private:
	UPROPERTY(VisibleAnywhere, Category = "Implementar builder")
		class ANaveEscuadrillasCazaBuilder* NaveEscuadrillasCazaBuilder;

	UPROPERTY(VisibleAnywhere, Category = "Implementar builder")
		class ADirectorNaveEscuadrillasBuilder* DirectorNaveEscuadrillasBuilder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
