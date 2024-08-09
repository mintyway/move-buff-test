// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "MoveBuffTest/Data/AttributeSetMacro.h"
#include "MBTAttributSet.generated.h"

/**
 * 
 */
UCLASS()
class MOVEBUFFTEST_API UMBTAttributSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UMBTAttributSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	ATTRIBUTE_ACCESSORS(ThisClass, HP);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxHP);
	ATTRIBUTE_ACCESSORS(ThisClass, MoveSpeed);

protected:
	UFUNCTION()
	void OnRep_HP(const FGameplayAttributeData& OldValue) { GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, HP, OldValue); }

	UFUNCTION()
	void OnRep_MaxHP(const FGameplayAttributeData& OldValue) { GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxHP, OldValue); }

	UFUNCTION()
	void OnRep_MoveSpeed(const FGameplayAttributeData& OldValue) { GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MoveSpeed, OldValue); }

	UPROPERTY(BlueprintReadOnly, Category = "Stat", ReplicatedUsing = "OnRep_HP")
	FGameplayAttributeData HP;

	UPROPERTY(BlueprintReadOnly, Category = "Stat", ReplicatedUsing = "OnRep_MaxHP")
	FGameplayAttributeData MaxHP;

	UPROPERTY(BlueprintReadOnly, Category = "Stat", ReplicatedUsing = "OnRep_MoveSpeed")
	FGameplayAttributeData MoveSpeed;
};
