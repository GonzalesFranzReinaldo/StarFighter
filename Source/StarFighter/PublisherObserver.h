// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SubscriberObserver.h"
#include "PublisherObserver.generated.h"

UCLASS()
class STARFIGHTER_API APublisherObserver : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublisherObserver();

private:

	//The Subscribers of this Publisher
	UPROPERTY()
		TArray<AActor*> Subscribers = TArray<AActor*>(); // Array donde almacenaremos a todos los subcriptores

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//Add the pased Subscriber to the list  //Agregar el suscriptor pasado a la lista
	virtual void SubscribeShip(AActor* Subscriber);  // Suscribir a las Naves 

	//Remove the passed Subscriber from the list   // Eliminar el suscriptor pasado de la lista
	virtual void UnSubscribeShip(AActor* SubscriberToRemove);  // No suscribir a las nave

	//Notify all the Subscribers that something has changed //Notificar a todos los Suscriptores que algo ha cambiado
	virtual void NotifySubscribersShip();    // Notificar a las Naves Enemigas


};
