#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	ATank* GetPlayerControlledTank();
	ATank* GetControlledAITank();
	
public:
	void Tick(float DeltaTime);
};
