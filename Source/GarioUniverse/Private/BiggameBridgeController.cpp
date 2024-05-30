#include "BiggameBridgeController.h"

// Sets default values
ABiggameBridgeController::ABiggameBridgeController()
{

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BridgeController"));
	RootComponent = BoxComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BridgeMesh"));
	
}

void ABiggameBridgeController::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->Activate();
}

//actions calculated during bridge DEACTIVATION
void ABiggameBridgeController::DeactivateBridge_Process()
{
	UE_LOG(LogTemp, Warning, (TEXT("DeactivateBridge_Process")));
}

//call this one in BP shall we? 
//actions calculated on bridge DEACTIVATION FINISHED
void ABiggameBridgeController::DeactivateBridge_Finished()
{
	UE_LOG(LogTemp, Warning, (TEXT("DeactivateBridge_Finished")));

	BoxComponent->Deactivate();
	UE_LOG(LogTemp, Warning, (TEXT("BoxComponentDisabled")));
}

//actions calculated during bridge ACTIVATION
void ABiggameBridgeController::ActivateBridge_Process()
{
	UE_LOG(LogTemp, Warning, (TEXT("ActivateBridge_Process")));
}

//actions calculated on bridge ACTIVATION FINISHED
void ABiggameBridgeController::ActivateBridge_Finished()
{
	UE_LOG(LogTemp, Warning, (TEXT("ActivateBridge_Finished")));
}




