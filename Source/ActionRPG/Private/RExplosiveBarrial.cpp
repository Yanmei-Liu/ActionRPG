// Fill out your copyright notice in the Description page of Project Settings.


#include "RExplosiveBarrial.h"

#include "PhysicsEngine/RadialForceComponent.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCustom, Log, All);

// Sets default values
ARExplosiveBarrial::ARExplosiveBarrial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseComp = CreateDefaultSubobject<UStaticMeshComponent>("BaseComp");
	BaseComp->SetSimulatePhysics(true);
	RootComponent = BaseComp;

	RadialComp = CreateDefaultSubobject<URadialForceComponent>("RadialComp");
	RadialComp->SetupAttachment(BaseComp);

	RadialComp->SetAutoActivate(false);

	RadialComp->Radius = 750.0f;
	RadialComp->ImpulseStrength = 2500.0f;
	RadialComp->bImpulseVelChange = true;

	RadialComp->AddCollisionChannelToAffect(ECC_WorldDynamic);

}


void ARExplosiveBarrial::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	BaseComp->OnComponentHit.AddDynamic(this, &ARExplosiveBarrial::OnActorHit);
}


void ARExplosiveBarrial::OnActorHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector Impulse, const FHitResult& Hit)
{
	RadialComp->FireImpulse();

	UE_LOG(LogTemp, Log, TEXT("OnActorHit in Explosive Barrial"));
	UE_LOG(LogTemp, Warning, TEXT("OnActorHit: OtherActor: %s, at time: %f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);

	FString CombinedString = FString::Printf(TEXT("Hit at location: %s"), *Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(), Hit.ImpactPoint, CombinedString, nullptr, FColor::Green, 2.0f, true);
}



// Called when the game starts or when spawned
void ARExplosiveBarrial::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARExplosiveBarrial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

