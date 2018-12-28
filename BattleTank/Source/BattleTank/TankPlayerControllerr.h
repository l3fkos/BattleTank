// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerControllerr.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerControllerr : public APlayerController
{
	GENERATED_BODY()

private:
	bool GetSightRayHitLocation(FVector& HitLocation)const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;
	

public:
	ATank* GetControlledTank() const;
	void Tick(float DeltaTime);

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
		
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.;

	void AimTowardsCrosshair();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};


