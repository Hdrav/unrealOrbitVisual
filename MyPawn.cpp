// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f; // Set the desired arm length
	SpringArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create and attach the Camera component
	Camera2 = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera2->SetupAttachment(SpringArm, USpringArmComponent::SocketName); // Attach the camera to the end of the spring arm
	Camera2->bUsePawnControlRotation = false; // Don't rotate the camera when the controller rotates
}

void AMyPawn::DirectionalClickMovement() 
{
	FHitResult OutHitResult;
	USceneComponent* SceneRoot = this->GetRootComponent();
	APlayerController* PlayerController = GetController<APlayerController>();
	//ETraceTypeQuery::TraceTypeQuery1
	PlayerController->GetHitResultUnderCursorByChannel(ETraceTypeQuery::TraceTypeQuery1, true, OutHitResult);
	SceneRoot->SetWorldLocation(OutHitResult.Location);


}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

