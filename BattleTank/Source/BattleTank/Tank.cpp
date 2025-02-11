// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Public/TankBarrel.h"
#include "Public/TankAimingComponent.h"
#include "Public/TankBarrel.h"
#include "Public/Projectile.h"
#include "Public/TankTurret.h"

// Sets default values
ATank::ATank(){
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay(){
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation){
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet){
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet){
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire(){
		UE_LOG(LogTemp, Warning, TEXT("Fire!"))
		
			if (!Barrel){return;}

		FVector SocketVector = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator SocketRotator = Barrel->GetSocketRotation(FName("Projectile"));

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint, SocketVector, SocketRotator);
		Projectile->LaunchProjectile(LaunchSpeed);

}