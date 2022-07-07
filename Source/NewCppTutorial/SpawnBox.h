// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "SpawnBox.generated.h"

UCLASS()
class NEWCPPTUTORIAL_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when the actor stops playing
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Will spawn an actor of the specified class now
	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	// Change if actors are spawned
	UFUNCTION(BlueprintCallable)
	void EnableActorSpawning(bool Enable);

private:
	UFUNCTION()
	void SpawnActorScheduled();

    // Will schedule an actor spawn 
    void ScheduleActorSpawn();

public:
	// Actor class to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassToBeSpawned;

	// Average time between spawns (without random)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 5.f;
	// Random +/- offset of the spawn time
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RandomSpawnTimeOffset = 1.f;

private:
	// Box in which we will spawn the actors
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	// Indicates that the actor should spawn actors
    UPROPERTY(EditAnywhere)
    bool ShouldSpawn = true;

	// Helper for timing
	FTimerHandle SpawnTimerHandle;
};
