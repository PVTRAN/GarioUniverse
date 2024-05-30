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
	
	//Once there was a bridge that natively had collision
	UPROPERTY(EditAnywhere, Category="BigGame")
	UBoxComponent *BoxComponent_Bridge; 
	
	//that bridge also would dissapear...
	UFUNCTION(BlueprintCallable, Category="BigGame")
	void disableBridge();
	
	//that bridge would also re-appear! but could at any moment dissapear again. 
	UFUNCTION(BlueprintCallable, Category="BigGame")
	void enableBridge();
	
	
};




















//UFUNCTION(BlueprintCallable, Category="BigGameNew")
//virtual void DeactivateBridge_Process() override;