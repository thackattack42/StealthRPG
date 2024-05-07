// Fill out your copyright notice in the Description page of Project Settings.


#include "ABP_RPGCharcter_Code.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include "../../../RPG_Tutorial_SeriesCharacter.h"

UABP_RPGCharcter_Code::UABP_RPGCharcter_Code()
{
	isFalling = false;
	isCrouched = false;
}

void UABP_RPGCharcter_Code::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Character = Cast<ARPG_Tutorial_SeriesCharacter>(TryGetPawnOwner());

	if (Character != nullptr)
		CharacterMovement = Cast<UCharacterMovementComponent>(Character->GetMovementComponent());
}

void UABP_RPGCharcter_Code::NativeUpdateAnimation(float DeltaTimeX)
{
	Super::NativeUpdateAnimation(DeltaTimeX);

	if (Character != nullptr)
	{
		// Set Speed and Velocity
		DeltaTime = DeltaTimeX;
		Velocity = CharacterMovement->Velocity;
		Speed = Velocity.Length();

		// Set isFalling
		isFalling = CharacterMovement->IsFalling();

		// Set isCrouched
		isCrouched = Character->Crouched;

		// Calculate Lean
		FRotator Norm = LastFrameRotation - Character->GetActorRotation();
		Norm.Normalize();
		float NormYaw = Norm.Yaw;
		NormYaw /= DeltaTime;
		NormYaw /= 10;
		YawDelta = FMath::FInterpTo(YawDelta, NormYaw, DeltaTime, 10);
		LastFrameRotation = Character->GetActorRotation();
	}
}