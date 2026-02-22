// Fill out your copyright notice in the Description page of Project Settings.


#include "cPlayer.h"
#include "Engine/Engine.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AcPlayer::AcPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Root Scene
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;
	// Sphere
	resSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	resSphere->InitSphereRadius(50.f);
	resSphere->SetupAttachment(RootScene);
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

	UE_LOG(LogTemp, Warning, TEXT("working"));
}

// Called to bind functionality to input
void AcPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

