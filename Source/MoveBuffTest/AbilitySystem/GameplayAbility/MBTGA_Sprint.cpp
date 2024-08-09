// Fill out your copyright notice in the Description page of Project Settings.


#include "MBTGA_Sprint.h"

#include "AbilitySystemComponent.h"
#include "MoveBuffTest/AbilitySystem/Tag/MBTTags.h"
#include "MoveBuffTest/Character/MBTCharacter.h"

UMBTGA_Sprint::UMBTGA_Sprint()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateNo;
}

void UMBTGA_Sprint::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AMBTCharacter* SourceCharacter = Cast<AMBTCharacter>(ActorInfo->AvatarActor.Get());
	if (!ensureAlways(SourceCharacter))
	{
		K2_EndAbility();
		return;
	}

	UAbilitySystemComponent* SourceASC = ActorInfo->AbilitySystemComponent.Get();
	if (!ensureAlways(SourceASC))
	{
		K2_EndAbility();
		return;
	}

	if (SourceCharacter->HasAuthority())
	{
		GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Yellow, TEXT("스프린트 시작!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::White, TEXT("스프린트 시작!"));
	}

	FGameplayEffectSpecHandle GESpecHandle = SourceASC->MakeOutgoingSpec(SprintGE, 1.0f, SourceASC->MakeEffectContext());
	if (!ensureAlways(GESpecHandle.IsValid()))
	{
		K2_EndAbility();
		return;
	}

	GESpecHandle.Data->SetSetByCallerMagnitude(MBTTags::Attribute::MoveSpeed, SprintMultiplier);
	SprintGEHandle = SourceASC->BP_ApplyGameplayEffectSpecToSelf(GESpecHandle);
}

void UMBTGA_Sprint::InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
	Super::InputReleased(Handle, ActorInfo, ActivationInfo);

	K2_EndAbility();
}

void UMBTGA_Sprint::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	AMBTCharacter* SourceCharacter = Cast<AMBTCharacter>(ActorInfo->AvatarActor.Get());
	if (!ensureAlways(SourceCharacter))
	{
		Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
		return;
	}

	UAbilitySystemComponent* SourceASC = ActorInfo->AbilitySystemComponent.Get();
	if (!ensureAlways(SourceASC))
	{
		Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
		return;
	}

	if (SourceCharacter->HasAuthority())
	{
		GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Yellow, TEXT("스프린트 종료!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::White, TEXT("스프린트 종료!"));
	}

	SourceASC->RemoveActiveGameplayEffect(SprintGEHandle);

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
