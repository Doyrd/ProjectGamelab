#include "ControllerAI.h"
#include "Waypoint.h"
#include "AI.h"

AAI::AAI()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAI::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), Waypoints);
	MoveToWaypoints();
}

void AAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AAI::MoveToWaypoints() 
{
	AControlllerAI* ControllerAI = Cast<AControllerAI>(GetController());

	if (ControllerAI) 
	{
		if (currentWaypoint <= Waypoints.Num()) 
		{
			for (AActor* Waypoint : Waypoints) 
			{
				AWaypoint* WaypointItr = Cast<AWaypoint>(Waypoint);

				if (waypointItr) 
				{
					if (waypointItr->GetWaypointOrder() == CurrentWaypoint)
					{
						ControllerAI->MoveToActor(WaypointItr, 5.f, false);
						currentWaypoint++;
						break;
					}
				}
			}
		}
	}
}

