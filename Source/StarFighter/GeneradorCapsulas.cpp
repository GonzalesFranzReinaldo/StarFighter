// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulas.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "TimerManager.h"
#include "Capsula.h"



// Sets default values
AGeneradorCapsulas::AGeneradorCapsulas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGeneradorCapsulas::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AGeneradorCapsulas::repetir, 30.0f, true, 5.0f);
}

// Called every frame
void AGeneradorCapsulas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ACapsula* AGeneradorCapsulas::GetCapsula(FString NombreTipoCapsula)
{
	ACapsula* Capsula = FabricarCapsula(NombreTipoCapsula);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Fabricando capsulas %s"), *Capsula->GetNombre()));
	Capsula->Generar();
	Capsula->Cargar();
	Capsula->Desplegar();
	Capsula->Destruir();

	return Capsula;
}

void AGeneradorCapsulas::repetir()
{
	UE_LOG(LogTemp, Warning, TEXT("Creando Capsulas"));
	float newX = rand() % 100 + 1;
	float newY = rand() % 100 + 1;
	UWorld* const World = GetWorld();
	World->SpawnActor<ACapsula>(FVector(newX, newY, 200), FRotator::ZeroRotator);
}
