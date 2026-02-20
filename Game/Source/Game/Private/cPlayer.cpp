// Fill out your copyright notice in the Description page of Project Settings.


#include "cPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"

// Sets default values
AcPlayer::AcPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Constructor Manual Gen
		// Root Capsule
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->InitCapsuleSize(42.f, 96.0f);
	RootComponent = Capsule;

		// Spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;

		// Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;


}

// Called when the game starts or when spawned
void AcPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AcPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update Loop
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Test"));
	}

	UE_LOG(LogTemp, Error, TEXT("tick working"));
}

// Called to bind functionality to input
void AcPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

