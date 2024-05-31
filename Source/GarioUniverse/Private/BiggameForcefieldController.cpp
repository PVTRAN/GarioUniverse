// Fill out your copyright notice in the Description page of Project Settings.


#include "BiggameForcefieldController.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/TimelineComponent.h"

ABiggameForcefieldController::ABiggameForcefieldController()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Cube_ForcefieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube_ForcefieldMesh"));
    RootComponent = Cube_ForcefieldMesh;
	
    Timeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("ShutdownTimeline"));
	
}

//activating the forcefield controller onBeginPlay
void ABiggameForcefieldController::BeginPlay()
{
	Super::BeginPlay();

    //If this object is the forcefield mesh
	 if (Cube_ForcefieldMesh && BaseMaterial)
    {
	     //make a dynamic materialObject filled with properties from ForcefieldMesh
        DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
	     //setting our forcefield with the material that we also set to dynamic
	 	Cube_ForcefieldMesh->SetMaterial(0, DynamicMaterial);
    }
	
    //InitializeTimeline();
}


void ABiggameForcefieldController::PlayTimeline()
{
    //if timeline object
    if (Timeline)
    {
        Timeline->PlayFromStart();
    }
}

// Updating the Shutdown function
void ABiggameForcefieldController::UpdateShutdown(float ShutdownFloat)
{
    if (DynamicMaterial)
    {
    	//This is meant to help the material vanish 
        DynamicMaterial->SetScalarParameterValue(FName("Float Value Shutdown"), ShutdownFloat);
    }
}


//Finishing the shutdown function
void ABiggameForcefieldController::FinishShutdown()
{
	//play animation and possibly disable
}
















//DEPRECATED

//First need to be sure that the float curve is initialized and exists
	
/*if (FloatCurve)
{
	//This is just the float value that we will be modifying :: FOnTimelineFloat is also a delegate 
	FOnTimelineFloat UpdateCallback;
	//binding that float value to call the function "update disolve" via delegate. 
	UpdateCallback.BindUFunction(this, FName("UpdateDisolve"));

	Timeline->AddInterpFloat(FloatCurve, UpdateCallback);

	//These are delegates that are calling these functions out of their scope. 
	FOnTimelineEvent FinishCallback;
	FinishCallback.BindUFunction(FloatCurve, FName("FinishDissolve"));
	Timeline->SetTimelineFinishedFunc(FinishCallback);
	
}*/

//initializing the timeline 
/*void ABiggameForcefieldController::InitializeTimeline()
{
	/#1#/null check 
	if (Timeline)
	{
		
		FOnTimelineFloat UpdateCallback;
		UpdateCallback.BindUFunction(this, FName("UpdateShutdown"));
		Timeline->AddInterpFloat(FloatCurve, UpdateCallback);
		
		FOnTimelineEvent FinishCallback;
		FinishCallback.BindUFunction(this, FName("FinishShutdown"));
		Timeline->SetTimelineFinishedFunc(FinishCallback);
		
	}#1#
}*/