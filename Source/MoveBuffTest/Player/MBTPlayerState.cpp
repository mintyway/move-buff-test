// Fill out your copyright notice in the Description page of Project Settings.


#include "MBTPlayerState.h"

#include "AbilitySystemComponent.h"

AMBTPlayerState::AMBTPlayerState()
{
	NetUpdateFrequency = 30.f;

	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AMBTPlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}
