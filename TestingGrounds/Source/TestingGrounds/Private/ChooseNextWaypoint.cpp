#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(this->Index.SelectedKeyName);

	UE_LOG(LogTemp, Warning, TEXT("Waypoint %i"), Index);

	return EBTNodeResult::Succeeded;
}
