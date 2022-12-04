// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "WildernessCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class WILDERNESS_API AWildernessCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWildernessCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*
	 * Input Mapping Context/Input Actions for UE5 Enhanced Input System
	 */
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* WildernessContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MovementAction;

	void Move(const FInputActionValue& Value);

};
