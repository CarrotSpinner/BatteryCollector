// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// Returns the WhereToSpawn subobject
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; };

public:
	// Finds a random point within the box component
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointsInVolume();

protected:
	// The pickup to spawn
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

private:
	// The box component to specify where pickups should be spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;
	
private:
	// Handle spawning a new pickup
	void SpawnPickup();

protected:
	// Timer handle
	FTimerHandle SpawnTimer;

protected:
	//Minimum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

protected:
	//Maximum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

private:
	// The current spawn delay
	float SpawnDelay;
};
