// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"
//#include "Kismet/GameplayStatics.h"
//#include "Engine/CollisionProfile.h"
//#include "GameFramework/SpringArmComponent.h"


ABomba::ABomba()
{
	// Use a sphere as a simple collision representation
	/*CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComponent->InitSphereRadius(5.0f);
	CollisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComponent->OnComponentHit.AddDynamic(this, &ABomba::OnHit);		// set up a notification for when this component hits something

	// Players cant walk on it
	CollisionComponent->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComponent->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComponent;*/

}

/*void ABomba::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this))
	{

		OnDetonate();
	}
} */

void ABomba::BeginPlay()
{
	/*Super::BeginPlay();
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &ABomba::OnDetonate, 5.f, false);*/
}

/*void ABomba::OnDetonate()
{
	UParticleSystemComponent* Explosion = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetActorTransform());
	Explosion->SetRelativeScale3D(FVector(4.f));

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	TArray<FHitResult>HitActors;
	 
	FVector StartTrace = GetActorLocation();
	FVector EndTrace = StartTrace;
	EndTrace.Z += 300.f;

	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(Radius);

	if (GetWorld()->SweepMultiByChannel(HitActors, StartTrace, EndTrace, FQuat::FQuat(), ECC_WorldStatic, CollisionShape))
	{
		for (auto Actors = HitActors.CreateIterator(); Actors; Actors++)
		{

			UStaticMeshComponent* SM = Cast<UStaticMeshComponent>((*Actors).Actor->GetRootComponent());
			ADestructibleActor* DA = Cast<ADestructibleActor>((*Actors).GetActor());

			if (SM)
			{
				SM->AddRadialImpulse(GetActorLocation(), 1000.f, 5000.f, ERadialImpulseFalloff::RIF_Linear, true);
			}
			else if (DA)  
			{
				DA->GetDestructibleComponent()->ApplyRadiusDamage(10.f, Actors->ImpactPoint, 500.f, 3000.f, false);
			}
		}
	}
	Destroy();
}*/
