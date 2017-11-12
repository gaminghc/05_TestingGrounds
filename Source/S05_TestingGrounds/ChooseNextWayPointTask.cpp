// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPointTask.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UChooseNextWayPointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	//UE_LOG(LogTemp, Warning, TEXT("AI in C++ - YAY!"));
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("Waypoint index %i"), Index);
	return EBTNodeResult::Succeeded;
}

