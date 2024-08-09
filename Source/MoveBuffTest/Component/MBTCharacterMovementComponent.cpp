// Fill out your copyright notice in the Description page of Project Settings.


#include "MBTCharacterMovementComponent.h"


UMBTCharacterMovementComponent::UMBTCharacterMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UMBTCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UMBTCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
