// Fill out your copyright notice in the Description page of Project Settings.


#include "MBTPlayerState.h"

#include "AbilitySystemComponent.h"
#include "MoveBuffTest/AbilitySystem/AttributeSet/MBTAttributSet.h"

AMBTPlayerState::AMBTPlayerState()
{
	NetUpdateFrequency = 30.f;

	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UMBTAttributSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AMBTPlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}

UMBTAttributSet* AMBTPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
