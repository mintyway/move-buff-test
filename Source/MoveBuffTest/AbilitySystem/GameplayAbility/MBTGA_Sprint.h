// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MBTGA_Sprint.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MOVEBUFFTEST_API UMBTGA_Sprint : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UMBTGA_Sprint();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Design")
	TSubclassOf<UGameplayEffect> SprintGE;

	FActiveGameplayEffectHandle SprintGEHandle;

	UPROPERTY(EditAnywhere, Category = "Design")
	float SprintMultiplier = 1.5f;
};
