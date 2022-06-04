// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemigaBuilder.h"
#include "DirectorNaveEnemigaBuilder.generated.h"

UCLASS()
class STARFIGHTER_API ADirectorNaveEnemigaBuilder : public AActor
{
	GENERATED_BODY()
	
private:
	INaveEnemigaBuilder* NaveEnemigaBuilder;

public:	
	// Sets default values for this actor's properties
	ADirectorNaveEnemigaBuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ConstruirNavesEnemigas();
	void SetNaveEnemigaBuilder(AActor* Builder);
	class ANavesEnemigas* GetNavesEnemigas();

};
