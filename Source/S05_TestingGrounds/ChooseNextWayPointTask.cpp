// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPointTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "PatrolRouteComponent.h"



EBTNodeResult::Type UChooseNextWayPointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	// Get patrolling points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRouteComponent = ControlledPawn->FindComponentByClass<UPatrolRouteComponent>();
	// Protect against no or empty patrol route
	if (!ensure(PatrolRouteComponent)) { return EBTNodeResult::Failed; }
	auto PatrolPoints = PatrolRouteComponent->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("Patrol points empty!!!"));
		return EBTNodeResult::Failed;
	}

	// Set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index %i"), Index);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Set next index
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, ((++Index) %  PatrolPoints.Num()));
	
	return EBTNodeResult::Succeeded;
}

