// Fill out your copyright notice in the Description page of Project Settings.


#include "RItemChest.h"

// Sets default values
ARItemChest::ARItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	TargitRotationAngle = 110;
}


void ARItemChest::Interact_Implementation(APawn* TriggerPawn)
{
#if 0
	// Get the root component of the actor
	USceneComponent* RootComp = GetRootComponent();

	// Set the pivot point of the root component
	FVector NewPivotPoint = FVector(0.f, 0.f, 50.f); // Set the pivot point 50 units above the origin of the actor's local coordinate system
	RootComp->SetRelativeLocation(NewPivotPoint);
#endif

	// Get the current rotation of the lid
	FRotator CurrentRotation = LidMesh->GetRelativeRotation();

	// Calculate the new rotation of the lid by adding the desired rotation angle
	FRotator NewRotation = FRotator(CurrentRotation.Pitch, CurrentRotation.Yaw, CurrentRotation.Roll + TargitRotationAngle);

	LidMesh->SetRelativeRotation(FRotator(0, 0, TargitRotationAngle));

}

// Called when the game starts or when spawned
void ARItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

