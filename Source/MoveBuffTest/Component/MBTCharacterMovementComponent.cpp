// Fill out your copyright notice in the Description page of Project Settings.


#include "MBTCharacterMovementComponent.h"

#include "MoveBuffTest/Character/MBTCharacter.h"

UMBTCharacterMovementComponent::UMBTCharacterMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

float UMBTCharacterMovementComponent::GetMaxSpeed() const
{
	AMBTCharacter* SourceCharacter = GetOwner<AMBTCharacter>();
	if (!SourceCharacter)
	{
		return Super::GetMaxSpeed();
	}

	return SourceCharacter->GetMoveSpeed();
}
