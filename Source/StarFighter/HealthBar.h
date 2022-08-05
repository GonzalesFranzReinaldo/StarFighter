// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS(abstract)
class STARFIGHTER_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

protected:
	/*UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentHealthLabel;;

	UPROPERTY(meta = (BindWidget))
		class UTexBlock* MaxHealthLabel;*/
};
