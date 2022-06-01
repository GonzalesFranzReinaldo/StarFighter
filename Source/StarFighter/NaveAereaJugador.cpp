// Fill out your copyright notice in the Description page of Project Settings.

// N:11 declaramos los encabezados para crear  las camaras
#include "NaveAereaJugador.h"
#include "Proyectil.h"
#include "MyInventoryActor.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
// N: 8 declarar las clase de mover Moveforward y right en naveAereajugador
const FName ANaveAereaJugador::MoveForwardBinding("MoveForward");
const FName ANaveAereaJugador::MoveRightBinding("MoveRight");

ANaveAereaJugador::ANaveAereaJugador()
{
	// Cache our sound boom...
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	//N:10 creamos la camara para el navejugador en su constructor
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

	FireForwardValue = 0.0f;
	FireRightValue = 0.0f;

	Vida = 80;

	//Inventario
	CurrentInventory = CreateDefaultSubobject<UMyInventoryComponent>("MyInventory");

	//Ship Info
	ShipInfo.Add("IncrementarVida", 80);
	ShipInfo.Add("DecrementarVida", 80);
	ShipInfo.Add("IncrementarVelocidad", 0);
	ShipInfo.Add("DecrementarVelocidad", 0);
	ShipInfo.Add("Proyectil", 0);

}

void ANaveAereaJugador::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// N:13 asignar las entradas de movimiento enla navejugador
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	InputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ANaveAereaJugador::Fire);
	InputComponent->BindAction(TEXT("DropItem"), IE_Pressed, this, &ANaveAereaJugador::DropItem);
	InputComponent->BindAction(TEXT("ShowInventory"), IE_Pressed, this, &ANaveAereaJugador::ShowInventory);
	InputComponent->BindAction(TEXT("Test"), IE_Pressed, this, &ANaveAereaJugador::Test);
	InputComponent->BindAction(TEXT("IncrementarVelocidad"), IE_Pressed, this, &ANaveAereaJugador::IncrementarVelocidad);
	InputComponent->BindAction(TEXT("DecrementarVelocidad"), IE_Pressed, this, &ANaveAereaJugador::DecrementarVelocidad);
	//InputComponent->BindAction(TEXT("Mojora_Empeora_Proyectil"), IE_Pressed, this, &ANaveAereaJugador::Mojora_Empeora_Proyectil);
}

void ANaveAereaJugador::Tick(float DeltaSeconds)
{

	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	if (ForwardValue != 0.0f || RightValue != 0.0f) {
		if (ForwardValue != FireForwardValue) {
			FireForwardValue = ForwardValue;
		}
		if (RightValue != FireRightValue) {
			FireRightValue = RightValue;
		}
	}

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

    // Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

	}
}

void ANaveAereaJugador::IncrementarVelocidad()
{

	FString v = "IncrementarVelocidad";
	// Presione la tecla "2" para Incrementar Velocidad

		for (auto& pair : ShipInfo) {

			if (pair.Key == v) {

				if (pair.Value > 0) {
					pair.Value = pair.Value + 1;
					MoveSpeed = MoveSpeed + 800;
				}
				break;
			}
		}
}

void ANaveAereaJugador::DecrementarVelocidad()
{

	FString dv = "DecrementarVelocidad";
	// Presione la tecla "2" para Incrementar Velocidad

	for (auto& pair : ShipInfo) {

		if (pair.Key == dv) {

			if (pair.Value > 0) {
				pair.Value = pair.Value - 1;
				MoveSpeed = MoveSpeed - 350;
			}
			break;
		}
	}
}

void ANaveAereaJugador::Fire() {
	bCanFire = true;

	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.0f).GetClampedToMaxSize(1.0f);

	FireShot(FireDirection);

}

void ::ANaveAereaJugador::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaJugador::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());

			}

			bCanFire = false;
		}
	}
}

void ANaveAereaJugador::ShotTimerExpired()
{
	bCanFire = true;
}

void ANaveAereaJugador::TakeItem(AMyInventoryActor* MyInventoryItem)
{
	MyInventoryItem->PickUp();
	CurrentInventory->AddToInventory(MyInventoryItem);
}

void ANaveAereaJugador::DropItem()
{
	if (CurrentInventory->ShipInventoryActor.Num() == 0)
	{
		return;
	}
	AMyInventoryActor* Item = CurrentInventory->ShipInventoryActor.Last();
	CurrentInventory->RemoveFromInventory(Item);
	//should probably use scaled bounding box
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void ANaveAereaJugador::ShowInventory()
{
	// Forma 1 De recorrer un Contenedor
	/**for (int32 i = 0; i < CurrentInventory->CurrentInventoryActor.Num(); i++) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Actor de nombre: %s"), *(CurrentInventory->CurrentInventoryActor[i]->GetInventoryActorName())));
	}*/

	/**Ejemplo de Cast
	FString k = "1";
	int32 l = 0;
	l = Cast<int32>(k);*/

	// Forma 2
	/**for (TArray<AMyInventoryActor*>::TIterator It(CurrentInventory->CurrentInventoryActor); It; ++It) { // TIterator es un puntero que me va dar el primer elemento

		FString n = Cast<AMyInventoryActor>(*It)->GetInventoryActorName();

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Actor de nombre: %s"), *n));
	}*/

	// Forma 3 de Mostrar la lista del objeto que la nave va comiendo
	/**for (auto It = CurrentInventory->CurrentInventoryActor.CreateConstIterator(); It; ++It) {
		FString n = Cast<AMyInventoryActor>(*It)->GetInventoryActorName();

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Actor de nombre: %s"), *n));
	}*/

	for (auto& Elem : ShipInfo) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));
	}

}

void ANaveAereaJugador::Test()
{
	TSet<int>EjemploSet;
	EjemploSet.Add(1);
	EjemploSet.Add(2);
	EjemploSet.Add(3);
	EjemploSet.Add(1);  //duplicate: won't be addeed
	EjemploSet.Add(1);  //duplicate: won't be addeed

	for (auto It = EjemploSet.CreateConstIterator(); It; ++It) {

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%d"), *It));
	}

}

void ANaveAereaJugador::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	for (auto& Elem : ShipInfo) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));
	}

	AMyInventoryActor* MyInventoryItem = Cast<AMyInventoryActor>(Other);
	if (MyInventoryItem != nullptr)
	{
		FString n = MyInventoryItem->GetInventoryActorName();

		for (auto& pair : ShipInfo) {
			if (pair.Key == n) {
				pair.Value = pair.Value + 1;
				break;
			}
		}

		TakeItem(MyInventoryItem);

	}
	
	FString dv = "IncrementarVida";

		for (auto& pair : ShipInfo) {

			if (pair.Key == dv) {

				if (pair.Value > 0) {

					pair.Value = pair.Value - 20;
					Vida = Vida + 20;
					break;
				}
			}
		}

	
	AMyInventoryActor* ChoqueP = Cast<AMyInventoryActor>(Other);
	if (ChoqueP != nullptr) {

		for (auto& Elem : ShipInfo) {
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));
		}

		FString v = "DecrementarVida";
		for (auto& pair : ShipInfo) {

			if (pair.Key == v) {

				if (pair.Value > 0) {

					pair.Value = pair.Value - 40;
					Vida = Vida - 40;

					if (Vida == 0) {

						SetActorTickEnabled(false);
						SetActorHiddenInGame(true);
						SetActorEnableCollision(false);
					}
					break;
				}
				else {
					pair.Value = pair.Value + 50;
					Vida = Vida + 50;
					break;
				}
			}
		}
	}

}

