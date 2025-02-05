// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaEnemigoNodriza.h"
#include "Proyectil.h"
#include "Singleton.h"
#include "Kismet/GameplayStatics.h"

ANaveAereaEnemigoNodriza::ANaveAereaEnemigoNodriza()
{
		//Search for existing Instances of this class
		//Buscar Instancias existentes de esta clase creando en un array
		TArray<AActor*> Instances;

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANaveAereaEnemigoNodriza::StaticClass(), Instances);

		if (Instances.Num() > 1)
		{
			//If exist at least one of them, set the instance with the first found one
			//Si existe al menos uno de ellos, establezca la instancia con el primero encontrado
			Instance = Cast<ANaveAereaEnemigoNodriza>(Instances[0]);

			//Agregar mensaje de depuración en pantalla                                         ya existe
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s already exists"),*Instance->GetName()));
			
			//Then Destroy this Actor
			//Entonces destruye a este actor
			Destroy();
		}

		MoveSpeedNaveNodriza = 50.0f;
		MovingTX = 0.0f;
		MovingTY = 0.0f;

		GunOffset = FVector(90.f, 0.f, 0.f);
		FireRate = 2.0f;
		bCanFire = true;
}

void ANaveAereaEnemigoNodriza::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ANaveAereaEnemigoNodriza::FireEnemigo, 01.0f, true, 2.0f);
}

void ANaveAereaEnemigoNodriza::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	srand(time(NULL));

	MovingTX = rand() % 20 - 10;
	MovingTY = rand() % 20 - 10;

	const FVector MoveDirection = FVector(MovingTX, MovingTY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeedNaveNodriza * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}

void ANaveAereaEnemigoNodriza::FireEnemigo()
{
	bCanFire = true;
	float RandX = rand() % 500 - 50;
	float RandY = rand() % 500 - 50;
	const FVector FireDirection = FVector(RandX, RandY, 0.0f).GetClampedToMaxSize(1.0f); 

	FireShot(FireDirection);


	/*bCanFire = true;
	const FVector FireDirection = FVector(MovingX, MovingY, 0.0f).GetClampedToMaxSize(1.0f);

	FireShot(FireDirection);*/
}

void ANaveAereaEnemigoNodriza::FireShot(FVector FireDirection)
{
	if (bCanFire == true)
	{
		//const FRotator FireRotation = FireDirection.Rotation();
		//const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		const FRotator FireRotation = FRotator(0.0, rand() % 500 - 50, 0.0);//toma una rotacion aleatoria 
		const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			World->SpawnActor<AProyectil>(SpawnLocation + FVector(50, -50, 0), FireRotation);
			World->SpawnActor<AProyectil>(SpawnLocation + FVector(-50, 50, 0), FireRotation);
			World->SpawnActor<AProyectil>(SpawnLocation + FVector(100, -100, 0), FireRotation);
			World->SpawnActor<AProyectil>(SpawnLocation + FVector(-100, 100, 0), FireRotation);

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaEnemigoNodriza::ShotTimerExpired, FireRate);
		}

		/*if (FireDirection.SizeSquared() > 0.0f)
		{

		}*/
	}
}

void ANaveAereaEnemigoNodriza::ShotTimerExpired()
{
	bCanFire = true;
}
