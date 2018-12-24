// Fill out your copyright notice in the Description page of Project Settings.
#include "Public/TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerControllerr.h"


void ATankAIController::BeginPlay(){
	
	Super::BeginPlay();

	auto PlayerTank = GetPlayerControlledTank();
	//if (!PlayerTank) 
		//UE_LOG(LogTemp, Warning, TEXT("Could not find player tank!"))
	//else
		//UE_LOG(LogTemp, Warning, TEXT("Player tank is: %s"), *PlayerTank->GetName())
}

ATank* ATankAIController::GetPlayerControlledTank(){
auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
return Cast<ATank>(PlayerTank);
}

ATank* ATankAIController::GetControlledAITank(){
	return Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerControlledTank()) {
		GetControlledAITank()->AimAt(GetPlayerControlledTank()->GetActorLocation());
	}

}