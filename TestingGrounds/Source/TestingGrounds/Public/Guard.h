#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Guard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPoints;
};
