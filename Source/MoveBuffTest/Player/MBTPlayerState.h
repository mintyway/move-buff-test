// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "MBTPlayerState.generated.h"

class UMBTAttributSet;
/**
 * 
 */
UCLASS(Abstract)
class MOVEBUFFTEST_API AMBTPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMBTPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> ASC;

	UPROPERTY(VisibleAnywhere, Category = "GAS")
	TObjectPtr<UMBTAttributSet> AttributeSet; 
};
