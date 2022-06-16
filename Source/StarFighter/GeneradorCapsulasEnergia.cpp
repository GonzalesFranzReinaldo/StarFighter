// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulasEnergia.h"
#include "CapsulaEnergia1.h"
#include "CapsulaVida1.h"

ACapsula* AGeneradorCapsulasEnergia::FabricarCapsula(FString NombreTipoCapsula)
{
    if (NombreTipoCapsula.Equals("Energia1")) 
    {
        return GetWorld()->SpawnActor<ACapsulaEnergia1>(ACapsulaEnergia1::StaticClass());
    }
    else if (NombreTipoCapsula.Equals("Vida1")) 
    {
        return GetWorld()->SpawnActor<ACapsulaVida1>(ACapsulaVida1::StaticClass());
    }
	return nullptr;
}
