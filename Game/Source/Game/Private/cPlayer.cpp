// Fill out your copyright notice in the Description page of Project Settings.


#include "cPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

// Sets default values
AcPlayer::AcPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Root Init
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	
	// Custom Components
	playerBase = CreateDefaultSubobject<UStaticMeshComponent>("PlayerBase");
	
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset (TEXT("/Engine/BasicShapes/Cube.Cube"));
	//if (CubeMeshAsset.Succeeded()) playerBase->SetStaticMesh(CubeMeshAsset.Object);
	//playerBase->SetWorldScale3D(FVector(0.25f, 0.25, 2.f));
	
    playerBase->SetSimulatePhysics(true);
    playerBase->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    playerBase->SetCollisionProfileName(TEXT("PhysicsActor"));
    playerBase->SetupAttachment(RootComponent);

    playerCamera = CreateDefaultSubobject<UCameraComponent>("DefaultCamera");
	playerCamera->SetupAttachment(playerBase);
	playerCamera->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AcPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	// Init Code
	playerController = GetWorld()->GetFirstPlayerController();
	// Player Camera
	playerCamera->Activate(true);
	playerCamera->SetRelativeLocation(FVector3d(0.0f, 0.0f, 150.f));
}

// Called every frame
void AcPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Update Code
	GetWorld()->GetFirstPlayerController()->GetInputMouseDelta(mouseX, mouseY);
	this->UpdateCamera();
	this->CheckMovement();
	this->UpdateMovement();
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
	FRotator camRot2 = camRot;
	camRot2.Roll = 0;
	camRot2.Pitch = 0;
	playerBase->SetRelativeRotation(camRot2);
}

void AcPlayer::CheckMovement()
{
	goForward = false;
	goLeft = false;
	goRight = false;
	goBackward = false;
	
	if (playerController->IsInputKeyDown(EKeys::W)) goForward = true;
	if (playerController->IsInputKeyDown(EKeys::A)) goLeft = true;
	if (playerController->IsInputKeyDown(EKeys::S)) goBackward = true;
	if (playerController->IsInputKeyDown(EKeys::D)) goRight = true;
}

void AcPlayer::UpdateMovement()
{
	if (goForward) playerBase->SetPhysicsLinearVelocity(playerBase->GetForwardVector() * this->playerAttributes.moveSpeed);
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

