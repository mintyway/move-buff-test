// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MBTCharacterMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MOVEBUFFTEST_API UMBTCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	// class FMBTSavedMove : public FSavedMove_Character
	// {
	// public:
	// 	using Super = FSavedMove_Character;
	// };
	//
	// class FMBTNetworkPredictionData_Client_Character : public FNetworkPredictionData_Client_Character
	// {
	// public:
	// 	using Super = FNetworkPredictionData_Client_Character;
	//
	// 	FMBTNetworkPredictionData_Client_Character(const UCharacterMovementComponent& ClientMovement);
	// };

public:
	UMBTCharacterMovementComponent();

	virtual float GetMaxSpeed() const override;
};
