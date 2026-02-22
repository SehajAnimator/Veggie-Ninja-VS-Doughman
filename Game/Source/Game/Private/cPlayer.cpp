// Fill out your copyright notice in the Description page of Project Settings.


#include "cPlayer.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"

// Sets default values
AcPlayer::AcPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Root Init
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	
	// Custom Components
	playerCamera = CreateDefaultSubobject<UCameraComponent>("DefaultCamera");
	playerCamera->SetupAttachment(RootComponent);
	playerCamera->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AcPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	// Init Code
	playerCamera->Activate(true);
	playerCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 150.f));
}

// Called every frame
void AcPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Update Code
	GetWorld()->GetFirstPlayerController()->GetInputMouseDelta(mouseX, mouseY);
	this->UpdateCamera();
}

// Called to bind functionality to input
void AcPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Custom Methods
void AcPlayer::UpdateCamera()
{
	FRotator camRot = playerCamera->GetRelativeRotation();
	camRot.Add(mouseY * this->GetSensitivity(), mouseX * this->GetSensitivity(), 0);
	playerCamera->SetRelativeRotation(camRot);
}

// Setters
void AcPlayer::SetSensitivity(float value)
{
	this->cameraSensitivity = value;
}

float AcPlayer::GetSensitivity()
{
	return this->cameraSensitivity;
}

