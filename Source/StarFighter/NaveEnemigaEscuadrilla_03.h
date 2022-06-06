// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveEnemigaEscuadrilla_03.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveEnemigaEscuadrilla_03 : public ANave
{
	GENERATED_BODY()
	
private:
	FString Bombardeo;
	FString Desaparecer;
	FString SistemaCrecer;

public:
	void SetBombardeo(FString _Bombardeo) { Bombardeo = _Bombardeo; }
	void SetDesaparecer(FString _Desaparecer) { Desaparecer = _Desaparecer; }
	void SetSistemaCrecer(FString _SistemaCrecer) { SistemaCrecer = _SistemaCrecer; }

	void CaracteristicasNaveEnemigaEscuadrilla_03();
};
