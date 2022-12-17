// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/HumanAnimInstance.h"

#include "Characters/WildernessCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UHumanAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// Initializing WildernessCharacter, but the owning pawn must first be casted to AWildernessCharacter type.
	WildernessCharacter = Cast<AWildernessCharacter>(TryGetPawnOwner());
	if (WildernessCharacter)
	{
		// Initializing our character movement component.
		WildernessCharacterMovement = WildernessCharacter->GetCharacterMovement();
	}
	
}

void UHumanAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (WildernessCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(WildernessCharacterMovement->Velocity);
		bIsFalling = WildernessCharacterMovement->IsFalling();
	}
}
