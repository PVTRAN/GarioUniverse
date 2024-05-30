// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BiggameForcefieldController.generated.h"

UCLASS()
class GARIOUNIVERSE_API ABiggameForcefieldController : public AActor
{
	GENERATED_BODY()
	
public:	
	ABiggameForcefieldController();

protected:
	virtual void BeginPlay() override;

public:
	//this makes sense because we are declaring and using a primitive component 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Big Game")
	UPrimitiveComponent* Cube_ForcefieldMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Big Game")
	UMaterialInterface* BaseMaterial; 

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Big Game")
	UMaterialInstanceDynamic* DynamicMaterial;

	//Not exposed 
	//---------------------------------------------------------------
	
	UPROPERTY(EditAnywhere, Category= "BigGame")
	class UTimelineComponent* Timeline;

	UPROPERTY(EditAnywhere, Category= "BigGame")
	UCurveFloat* FloatCurve;
	
	// Functions
	//-----------------------------------------

	UFUNCTION(BlueprintCallable, Category = "BigGame")
	void PlayTimeline();

	UFUNCTION(BlueprintCallable, Category = "BigGame")
	void UpdateShutdown(float Value);

	UFUNCTION(BlueprintCallable, Category = "BigGame")
	void FinishShutdown();

	//Hidden Functions
	//-----------------------------------------
	
private:
	void InitializeTimeline();

};
