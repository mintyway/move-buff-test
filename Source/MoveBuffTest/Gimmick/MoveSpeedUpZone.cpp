// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveSpeedUpZone.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Components/BoxComponent.h"
#include "MoveBuffTest/AbilitySystem/Tag/MBTTags.h"
#include "MoveBuffTest/Data/MBTCollision.h"


AMoveSpeedUpZone::AMoveSpeedUpZone()
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent")));

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(GetRootComponent());
	BoxCollider->SetCollisionProfileName(MBTCollision::Profile::MoveSpeedUpZone);
}

void AMoveSpeedUpZone::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		SetActorEnableCollision(false);
	}
}

void AMoveSpeedUpZone::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	if (!ensureAlways(ASC))
	{
		return;
	}

	FGameplayEffectSpecHandle GESpec = ASC->MakeOutgoingSpec(MoveSpeedUpGE, 1.0f, ASC->MakeEffectContext());
	if (!ensureAlways(GESpec.IsValid()))
	{
		return;
	}

	GESpec.Data->SetSetByCallerMagnitude(MBTTags::Attribute::MoveSpeed, MoveSpeedUpMultiflier);
	MoveSpeedUpHandle = ASC->BP_ApplyGameplayEffectSpecToSelf(GESpec);
	GEngine->AddOnScreenDebugMessage(3, 1.0f, FColor::Yellow, TEXT("진입"));
}

void AMoveSpeedUpZone::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	if (!ensureAlways(ASC))
	{
		return;
	}

	ASC->RemoveActiveGameplayEffect(MoveSpeedUpHandle);
	GEngine->AddOnScreenDebugMessage(3, 1.0f, FColor::Yellow, TEXT("탈출"));
}
