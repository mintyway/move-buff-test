// Fill out your copyright notice in the Description page of Project Settings.


#include "MBTAttributSet.h"

#include "Net/UnrealNetwork.h"

UMBTAttributSet::UMBTAttributSet()
{
	InitMaxHP(100.0f);
	InitHP(GetMaxHP());

	InitMoveSpeed(600.0f);
}

void UMBTAttributSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, HP);
	DOREPLIFETIME(ThisClass, MaxHP);
	DOREPLIFETIME(ThisClass, MoveSpeed);
}

void UMBTAttributSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UMBTAttributSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
}
