#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "Guard.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get the patrol route
	auto AIController = OwnerComp.GetAIOwner();
	auto AIGuard = Cast<AGuard>(AIController->GetPawn());
	auto PatrolPoints = AIGuard->GetPatrolPoints();

	// Select next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(this->Index.SelectedKeyName);
	
	// Cycle index
	if (PatrolPoints.Num() == 0) { return; }
	auto NextIndex = Index % PatrolPoints.Num();

	// Set the next index and the waypoint
	BlackboardComp->SetValueAsObject(this->Waypoint.SelectedKeyName, PatrolPoints[NextIndex]);
	BlackboardComp->SetValueAsInt(this->Index.SelectedKeyName, ++Index);

	UE_LOG(LogTemp, Warning, TEXT("%s going to Waypoint #%i"), *(AIGuard->GetName()), NextIndex);

	return EBTNodeResult::Succeeded;
}
