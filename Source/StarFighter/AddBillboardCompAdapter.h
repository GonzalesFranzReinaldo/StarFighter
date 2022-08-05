// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Adapter.h"
#include "AddBillboardCompAdapter.generated.h"


class AAddBillboardComp;
UCLASS()
class STARFIGHTER_API AAddBillboardCompAdapter : public AActor, public IAdapter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAddBillboardCompAdapter();

private:
	//The cartelera Actor
	UPROPERTY();
	    AAddBillboardComp* ShotEnemy;

	UPROPERTY()
		AAddBillboardComp* BombEnemy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Shooting() override;  // Dispara a la nave jugador
	void Bombing() override;  //  Bombardear a la nave jugador

};
