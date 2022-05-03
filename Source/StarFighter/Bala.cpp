// Fill out your copyright notice in the Description page of Project Settings.


#include "Bala.h"

ABala::ABala()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you dont need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	RootComponent = RootComp;


	ColaEnteros.Push(10);
	ColaEnteros.Push(3.4f);

	int ve = ColaEnteros.Pop();
	int vf = ColaFlotantes.Pop();

	UE_LOG(LogTemp, Warning, TEXT("ve: %d --> vf: %f"), ve, vf);
}

void ABala::BeginPlay()
{
	Super::BeginPlay();
}

void ABala::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitResult;

	FVector StartTrace = this->GetActorLocation();
	FVector EndTrace = (Velocity * DeltaTime) + StartTrace;
	EndTrace.Z += this->GetActorRotation().Pitch;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Destructible, CollisionParams))
	{

		if (HitResult.GetActor())
		{
			DrawDebugSolidBox(GetWorld(), HitResult.ImpactPoint, FVector(10.f), FColor::Blue, true);
			ADestructibleActor* Mesh = Cast<ADestructibleActor>(HitResult.GetActor());

			Mesh->GetDestructibleComponent()->ApplyRadiusDamage(10.f, HitResult.ImpactPoint, 32.f, 10.f, false);
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Could not get mesh. Type is: %s"), *HitResult.GetActor()->StaticClass()->GetFName().ToString()));
		}

		Destroy();

	}
	else {
		BulletExpiry += DeltaTime;

		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(0.f, -BulletExpiry * 80.f, 100.f));

		SetActorLocation(EndTrace);

		Velocity += FVector(0.f, 0.f, -200.f) * DeltaTime;
	}

	if (BulletExpiry > 3) {
		Destroy();
	}
}
