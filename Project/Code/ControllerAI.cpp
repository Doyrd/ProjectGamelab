// Fill out your copyright notice in the Description page of Project Settings.

#include "�I.h"
#include "ControllerAI.h"

void AControllerAI::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& result) 
{
	AAI* AI = Cast<AAI>(GetControllerdPawn());

	if (AI) 
	{
		AI->MoveToWaypoints();
	}
}


