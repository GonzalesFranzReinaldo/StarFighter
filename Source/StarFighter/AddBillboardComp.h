// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AddBillboardComp.generated.h"

UCLASS()
class STARFIGHTER_API AAddBillboardComp : public AActor
{
	GENERATED_BODY()
	
private:

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;

public:
	// Sets default values for this actor's properties
	AAddBillboardComp();

	FTimerHandle MemberTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate;

	UPROPERTY(VisibleAnywhere)
		class UBillboardComponent* MyBillboardComp;

	float RunningTime;

	void FireEnemigo();
	void FireShotEnemigo(FVector FireDirectionEnemigo);
	void ShotTimerExpired();

	/*float MovingTX;
	float MovingTY;*/
};
