// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerInput.h"
#include "cPlayer.generated.h"

UCLASS()
class GAME_API AcPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AcPlayer();

private:
	float cameraSensitivity = 3.f;
	float mouseX = 0, mouseY = 0;
	APlayerController* playerController;
	FInputKeyParams forwardParam;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Custom Component
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Default")
	UCameraComponent* playerCamera;
	
	// Custom Methods
	void UpdateCamera();
	void SetupKeybinds();
	void CheckMovement();
	// Setters
	void SetSensitivity(float value);
	// Getters
	float GetSensitivity();
};
