// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveAcuatico.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveAcuatico : public ANave
{
	GENERATED_BODY()

public:

	
	ANaveAcuatico();

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired; 
	FTimerHandle MemberTimerHandle;
	FTimerHandle MemberTimerHandle1;
public:

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate; 

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float MoveSpeedAcuatico;

	float MovingAX;
	float MovingAY; 

	TArray<FVector>Ubicacion;

public:

	virtual void BeginPlay() override;

	void Tick(float DeltaSeconds);

	void FireAcuatico(); 
	void FireShotAcuatico(FVector FireDirectionEnemigo); 
	void ShotTimerExpired();


public:

	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
			FVector NormalImpulse, const FHitResult& Hit)override;//esta funcion nos notifica cada golpe que de la clase.

	TMap<FString, int32>AcuaticoInfo;

	void CuentaBalas();
	void MuestraCuentaBalas();
};
