// Fill out your copyright notice in the Description page of Project Settings.


#include "PublisherObserver.h"

// Sets default values
APublisherObserver::APublisherObserver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APublisherObserver::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APublisherObserver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APublisherObserver::SubscribeShip(AActor* Subscriber)  // Subscribir a las naves
{
	//Add the passed Subscriber
	Subscribers.Add(Subscriber);
}

void APublisherObserver::UnSubscribeShip(AActor* SubscriberToRemove)  // Eliminar a los subscriptores
{
	// Remove the passed Subscriber
	Subscribers.Remove(SubscriberToRemove);
}

void APublisherObserver::NotifySubscribersShip() //Notificar a los subscriptores
{
	//Loop for each Subscriber 
	for (AActor* Actor : Subscribers)  // Iterador
	{
		//Cast each of them to a concrete Subscriber
		ISubscriberObserver* Sub = Cast<ISubscriberObserver>(Actor);
		if (Sub)
		{
			//Notify each of them that something has changed, so they can execute their own routine
			Sub->Update(this); // Sub toma apunta a Actualizar la notifySubscriber
		}
	}
}

