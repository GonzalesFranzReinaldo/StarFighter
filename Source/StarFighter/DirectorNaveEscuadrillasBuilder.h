// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaEspacial.h"
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

	void ConstruirNaveEnemigaEspacial();
	void SetNaveEscuadrillasBuilder(AActor* Builder);

	class ANaveEnemigaEspacial* GetNaveEnemigaEspacial();
};
