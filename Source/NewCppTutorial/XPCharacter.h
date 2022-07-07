// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Engine/StaticMesh.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "XPCharacter.generated.h"

UCLASS()
class NEWCPPTUTORIAL_API AXPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AXPCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void MoveFB(float Value);
	void MoveLR(float Value);
	void Rotate(float Value);

private:
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.0f;
	
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.0f;

	// Mesh being displayed
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;

	// Camera to view the scene
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* PlayerCamera;
};
