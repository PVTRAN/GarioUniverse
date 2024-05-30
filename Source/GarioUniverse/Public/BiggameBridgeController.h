#pragma once

#include "CoreMinimal.h"
#include "BridgeInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BiggameBridgeController.generated.h"

UCLASS()
class GARIOUNIVERSE_API ABiggameBridgeController : public AActor, public IBridgeInterface
{
	GENERATED_BODY()
	
public:
	ABiggameBridgeController();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category="BigGameNew")
	UBoxComponent* BoxComponent;
	
	UPROPERTY(EditAnywhere, Category="BigGameNew")
	UStaticMeshComponent* StaticMeshComponent;
	
	//need to turn it virtual to link myself up with the interface
	//and then override to change the interface 
	UFUNCTION(BlueprintCallable, Category="BigGameNew")
	virtual void DeactivateBridge_Process() override;
	
	UFUNCTION(BlueprintCallable, Category="BigGameNew")
	virtual void DeactivateBridge_Finished() override;
	
	UFUNCTION(BlueprintCallable, Category="BigGameNew")
	virtual void ActivateBridge_Process() override;
	
	UFUNCTION(BlueprintCallable, Category="BigGameNew")
	virtual void ActivateBridge_Finished() override;
	
	
};


