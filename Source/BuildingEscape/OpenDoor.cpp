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

	FRotator rotation = GetOwner()->GetActorRotation();

	rotation.Yaw = FMath::FInterpTo(rotation.Yaw, _doorTargetYaw, DeltaTime, 1);

	GetOwner()->SetActorRotation(rotation);

	UE_LOG(LogTemp, Warning, TEXT("Value of %s 's Yaw Value: %f, Target Yaw is: %f"), *GetOwner()->GetName(), rotation.Yaw, _doorTargetYaw);

}

void UOpenDoor::Init()
{
	//auto rotation = GetOwner()->GetActorRotation();
	_doorTargetYaw = GetOwner()->GetActorRotation().Yaw + 90.0f;
}