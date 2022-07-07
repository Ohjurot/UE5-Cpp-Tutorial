// Fill out your copyright notice in the Description page of Project Settings.


#include "XPCharacter.h"

// Sets default values
AXPCharacter::AXPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Setup component hierarchy
    PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
    PlayerMesh->SetupAttachment(GetCapsuleComponent());
    PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
    PlayerCamera->SetupAttachment(GetCapsuleComponent());
}

// Called when the game starts or when spawned
void AXPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
    
}

// Called every frame
void AXPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AXPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Register axis
    PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXPCharacter::MoveFB);
    PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXPCharacter::MoveLR);
    PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AXPCharacter::Rotate);
}

void AXPCharacter::MoveFB(float Value)
{
    AddMovementInput(GetActorForwardVector(), Value * MoveSpeed);
}

void AXPCharacter::MoveLR(float Value)
{
    AddMovementInput(-GetActorRightVector(), Value * MoveSpeed);
}

void AXPCharacter::Rotate(float Value)
{
    AddControllerYawInput(Value * RotationSpeed);
}
