// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerControllerr.h"
#include "BattleTank.h"
#include "Engine/World.h"


void ATankPlayerControllerr::BeginPlay(){

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player controller tank: %s"), *GetControlledTank()->GetName())
}

//Get the player controlled tank pawn
ATank* ATankPlayerControllerr::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

//Get the barrell to point towards where our reticle is
void ATankPlayerControllerr::AimTowardsCrosshair() {
	
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerControllerr::GetSightRayHitLocation(FVector& HitLocation)const{

	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	GetLookVectorHitLocation(LookDirection, HitLocation);

	return true;
}

bool ATankPlayerControllerr::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const {
	FVector WL;
	return GetWorld()->GetFirstPlayerController()->DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WL, LookDirection);
}

bool ATankPlayerControllerr::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}
	else {
		HitLocation = FVector(0);
		return false;
	}
		
}

void ATankPlayerControllerr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

