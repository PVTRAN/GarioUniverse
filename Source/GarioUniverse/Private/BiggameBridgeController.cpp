#include "BiggameBridgeController.h"

// Sets default values
ABiggameBridgeController::ABiggameBridgeController()
{
	//the Bridge was connecting two mythical points in space together
	BoxComponent_Bridge = CreateDefaultSubobject<UBoxComponent>(TEXT("BigGame.cpp"));
	//and the bridge was at the center of the world 
	RootComponent = BoxComponent_Bridge; 
}

void ABiggameBridgeController::BeginPlay()
{
	Super::BeginPlay();
}

void ABiggameBridgeController::disableBridge()
{
	//at the drop of a hat, the bridge could lose it's collision, if it was
	//a bridge
	if (BoxComponent_Bridge)
	{
		BoxComponent_Bridge->Deactivate();
	}
}

void ABiggameBridgeController::enableBridge()
{
	if (BoxComponent_Bridge)
	{
		BoxComponent_Bridge->Activate();
	}
}




