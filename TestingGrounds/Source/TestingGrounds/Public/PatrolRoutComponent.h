#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoutComponent.generated.h"

/*
 * A "route card" to help AI choose their next waypoint. 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TESTINGGROUNDS_API UPatrolRoutComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetPatrolPoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPoints;
};
