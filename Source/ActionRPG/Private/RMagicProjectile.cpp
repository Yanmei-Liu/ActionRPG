// Fill out your copyright notice in the Description page of Project Settings.


#include "RMagicProjectile.h"

#include "RAttributeComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ARMagicProjectile::ARMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	// SphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	// SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	// SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetCollisionProfileName("Projectile");
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ARMagicProjectile::OnActorOverlap);
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;
}

void ARMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		URAttributeComponent * AttributeComp = Cast<URAttributeComponent>(OtherActor->GetComponentByClass(URAttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			AttributeComp->ApplyHealthChange(-15.0f);

			Destroy();
		}
	}

}

// Called when the game starts or when spawned
void ARMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


