// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "MBTCharacter.generated.h"

class UMBTAttributSet;
class UMBTInputDataAsset;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UGameplayAbility;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UENUM()
enum class EActiveAbility
{
	Sprint
};

UCLASS(Abstract, config=Game)
class AMBTCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMBTCharacter(const FObjectInitializer& ObjectInitializer);

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

	float GetMoveSpeed() const;

protected:
	// To add mapping context
	virtual void BeginPlay();

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void InitASC();

	void SetupGASInput();

	void GASInputPressed(EActiveAbility InputID);

	void GASInputReleased(EActiveAbility InputID);

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY()
	TWeakObjectPtr<UAbilitySystemComponent> ASC;

	UPROPERTY()
	TWeakObjectPtr<UMBTAttributSet> AttributeSet;

	UPROPERTY(EditAnywhere, Category = "Design")
	TObjectPtr<UMBTInputDataAsset> InputDataAsset; 

	UPROPERTY(EditAnywhere, Category = "GAS")
	TSubclassOf<UGameplayAbility> SprintGA;
};
