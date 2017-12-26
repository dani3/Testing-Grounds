#include "PatrolRoutComponent.h"

TArray<AActor*> UPatrolRoutComponent::GetPatrolPoints() const
{
	return PatrolPoints;
}
