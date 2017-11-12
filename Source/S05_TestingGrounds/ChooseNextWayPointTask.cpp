// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPointTask.h"


EBTNodeResult::Type UChooseNextWayPointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	UE_LOG(LogTemp, Warning, TEXT("AI in C++ - YAY!"));
	return EBTNodeResult::Succeeded;
}

