// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"

#include "ABP_RPGCharcter_Code.generated.h"

/**
 * 
 */
UCLASS()
class RPG_TUTORIAL_SERIES_API UABP_RPGCharcter_Code : public UAnimInstance
{
	GENERATED_BODY()

public:
	UABP_RPGCharcter_Code();

protected:
	virtual void NativeInitializeAnimation();
	virtual void NativeUpdateAnimation(float DeltaTimeX);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	bool isFalling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	class ARPG_Tutorial_SeriesCharacter* Character;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	bool isCrouched;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	FRotator LastFrameRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	float DeltaTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	float YawDelta;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Variables, meta = (AllowPrivateAccess = "true"))
	class UCharacterMovementComponent* CharacterMovement;
};
