#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BridgeInterface.generated.h"

UINTERFACE()
class UBridgeInterface : public UInterface
{
	GENERATED_BODY()
};

class IBridgeInterface
{
	GENERATED_BODY()

public:
	//Activate Bridge
	//--------------------------------------
	virtual void ActivateBridge_Process();
	virtual void ActivateBridge_Finished();

	//Deactivate Bridge
	//--------------------------------------
	virtual void DeactivateBridge_Process();
	virtual void DeactivateBridge_Finished(); 
	
};

