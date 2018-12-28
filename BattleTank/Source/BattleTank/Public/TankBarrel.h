// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere)
	float MaxElevation = 40;

	UPROPERTY(EditAnywhere)
	float MinElevation = 0;

public:
	void ElevateBarrel(float RelativeSpeed);
	
};
