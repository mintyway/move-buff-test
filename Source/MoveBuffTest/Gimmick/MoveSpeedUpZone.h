// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameFramework/Actor.h"
#include "MoveSpeedUpZone.generated.h"

class UBoxComponent;
class UGameplayEffect;

UCLASS()
class MOVEBUFFTEST_API AMoveSpeedUpZone : public AActor
{
	GENERATED_BODY()

public:
	AMoveSpeedUpZone();

protected:
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UPROPERTY(VisibleAnywhere, Category = "Collider")
	TObjectPtr<UBoxComponent> BoxCollider;

	UPROPERTY(EditAnywhere, Category = "Design")
	TSubclassOf<UGameplayEffect> MoveSpeedUpGE;

	FActiveGameplayEffectHandle MoveSpeedUpHandle;

	UPROPERTY(EditAnywhere, Category = "Design")
	float MoveSpeedUpMultiflier = 5.f;
};
