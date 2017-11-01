// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABatteryPickup();
	
public:
	// override the WasCollected function = use Implemention because it's a BluePrint Native Event
	void WasCollected_Implementation() override;

	// public way to access the battery power level
	float GetPower();

protected:
	// set the amount of power the battery gives to the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float BatteryPower;
	
};
