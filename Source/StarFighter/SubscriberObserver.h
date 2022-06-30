// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SubscriberObserver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USubscriberObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTER_API ISubscriberObserver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//The pure virtual functions of the Subscriber
	virtual void Update(class APublisherObserver* PublisherObserver) = 0;  // Funcion pura actualizar

};
