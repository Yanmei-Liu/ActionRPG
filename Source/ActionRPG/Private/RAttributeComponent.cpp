// Fill out your copyright notice in the Description page of Project Settings.


#include "RAttributeComponent.h"

// Sets default values for this component's properties
URAttributeComponent::URAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Health = 100.0f;

	// ...
}


// Called when the game starts
void URAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


bool URAttributeComponent::ApplyHealthChange(float delta)
{
	Health += delta;

	OnHealthChanged.Broadcast(nullptr, this, Health, delta);

	return true;
}


// Called every frame
void URAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

