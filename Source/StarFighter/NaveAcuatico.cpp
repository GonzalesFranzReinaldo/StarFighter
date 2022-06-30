// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAcuatico.h"
#include "NaveAereaJugador.h"
#include "Kismet/GameplayStatics.h"
#include "Proyectil.h"
#include "StarFighterGameModeBase.h"
#include "NaveAereaEnemigoNodriza.h"

ANaveAcuatico::ANaveAcuatico()
{
	MoveSpeedAcuatico = 50.0f; 

	GunOffset = FVector(90.f, 0.f, 0.f); 
	FireRate = 2.0f;
	bCanFire = true;

	MovingAX = 0.0f;
	MovingAY = 0.0f;

	AcuaticoInfo.Add("Disparo", 0);

	Ubicacion.Add(FVector(0, 0, 0));

}
void ANaveAcuatico::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ANaveAcuatico::FireAcuatico, 01.0f, true, 0.0f);
	GetWorldTimerManager().SetTimer(MemberTimerHandle1, this, &ANaveAcuatico::MuestraCuentaBalas, 60.0f, true, 60);

}

void ANaveAcuatico::Tick(float DeltaSeconds)
{

	srand(time(NULL));

	MovingAX = rand() % 18 - 10;
	MovingAY = rand() % 18 - 10; 

	const FVector MoveDirection = FVector(MovingAX, MovingAY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeedAcuatico * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}

	ANaveAereaEnemigoNodriza* avatar = Cast<ANaveAereaEnemigoNodriza>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!avatar)
	{
		return;

	}
	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	toPlayer.Normalize();

	FRotator toPlayerRotation = toPlayer.Rotation(); 
	toPlayerRotation.Pitch = 0;
	RootComponent->SetWorldRotation(toPlayerRotation);

}

void ANaveAcuatico::FireAcuatico()
{

	bCanFire = true;
	const FVector FireDirectionAcuatico = FVector(MovingAX, MovingAY, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotAcuatico(FireDirectionAcuatico);
	CuentaBalas();
}

void ANaveAcuatico::FireShotAcuatico(FVector FireDirectionAcuatica)
{
	if (bCanFire == true)
	{
		if (FireDirectionAcuatica.SizeSquared() > 0.0f)
		{
			ANaveAereaJugador* avatar = Cast<ANaveAereaJugador>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		
			if (!avatar)
			{
				return;

			}
			FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();

			const FRotator FireRotation = toPlayer.Rotation(); //unimos el vector que apunta al jugador con una rotacion
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{

				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAcuatico::ShotTimerExpired, FireRate);//funcion que hace desaparecer la bala en un tiempo

		}
	}


}

void ANaveAcuatico::ShotTimerExpired()
{
	bCanFire = true;
}



void ANaveAcuatico::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	/*AProyectil* Choque = Cast<AProyectil>(Other); //solo en caso de que choque con un proyectil sera ejecutada la funcion de Destroy()
	if (Choque != nullptr)
	{

		Destroy();

	}*/
}



void ANaveAcuatico::CuentaBalas()
{

	FString VT = "Disparo";
	for (auto& pair : AcuaticoInfo)
	{
		if (pair.Key == VT)
		{
			if (pair.Value >= 0)
			{
				pair.Value = pair.Value + 1;

			}
		}
	}
}

void ANaveAcuatico::MuestraCuentaBalas()
{
	for (auto& Elem : AcuaticoInfo)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%s = %d"), *Elem.Key, Elem.Value));
	}
}