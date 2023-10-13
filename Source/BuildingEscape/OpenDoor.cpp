// Copyright Albert Koch 2023

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	this->Init();

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	this->Rotate(DeltaTime);
}

void UOpenDoor::Rotate(float DeltaTime)
{
	float doorTargetYaw = _doorTargetYaw;
	if (_isOpen)
		doorTargetYaw = _doorInitialYaw;

	_doorCurrentYaw = GetOwner()->GetActorRotation().Yaw;

	_doorCurrentYaw = FMath::FInterpTo(_doorCurrentYaw, doorTargetYaw, DeltaTime, 1);

	GetOwner()->SetActorRotation(FRotator(0.f, _doorCurrentYaw, 0.f));

	UE_LOG(LogTemp, Warning, TEXT("Value of %s 's Yaw Value: %f, Target Yaw is: %f, initially the door's Yaw was at: %f"), *GetOwner()->GetName(), _doorCurrentYaw, doorTargetYaw, _doorInitialYaw);

	UE_LOG(LogTemp, Warning, TEXT("Berechne: %f"), FMath::Abs(FMath::Abs(doorTargetYaw) - FMath::Abs(_doorCurrentYaw)))
	//Check if greater then 1 becaus 0 will (probably) never be reached
	if (FMath::Abs(FMath::Abs(doorTargetYaw) - FMath::Abs(_doorCurrentYaw)) < 1)
	{
		_isOpen = !_isOpen;
	}

}

void UOpenDoor::Init()
{
	_doorInitialYaw = GetOwner()->GetActorRotation().Yaw;
	_doorCurrentYaw = _doorInitialYaw;
}