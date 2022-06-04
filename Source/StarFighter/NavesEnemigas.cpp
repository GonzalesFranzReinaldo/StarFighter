// Fill out your copyright notice in the Description page of Project Settings.


#include "NavesEnemigas.h"

void ANavesEnemigas::CaracteristicasNavesEnemigas()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *SistemaDefensa));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *SistemaAtaque));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *SistemaDesplazamiento));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *SistemaCamuflaje));
}
