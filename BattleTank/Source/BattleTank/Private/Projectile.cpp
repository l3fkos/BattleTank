// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Projectile.h"

// Sets default values
AProjectile::AProjectile(){
 	
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement Component"));
	ProjectileMovementComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float Speed){
	UE_LOG(LogTemp, Warning, TEXT("Projectile fires at %f"), Speed)

	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector* Speed);
	ProjectileMovementComponent->Activate();
}

