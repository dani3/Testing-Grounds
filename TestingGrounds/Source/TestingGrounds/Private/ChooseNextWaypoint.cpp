#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "PatrolRoutComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get the patrol route
	auto AIController = OwnerComp.GetAIOwner();
	auto PatrolRoute = AIController->GetPawn()->FindComponentByClass<UPatrolRoutComponent>();

	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is missing patrol points"), *(AIController->GetPawn()->GetName()));

		return EBTNodeResult::Failed;
	}

	// Select next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(this->Index.SelectedKeyName);
	
	// Cycle index
	if (PatrolPoints.Num() == 0) { return EBTNodeResult::Failed; }
	auto NextIndex = Index % PatrolPoints.Num();

	// Set the next index and the waypoint
	BlackboardComp->SetValueAsObject(this->Waypoint.SelectedKeyName, PatrolPoints[NextIndex]);
	BlackboardComp->SetValueAsInt(this->Index.SelectedKeyName, ++Index);

	return EBTNodeResult::Succeeded;
}
