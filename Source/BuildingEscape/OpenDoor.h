// Copyright Albert Koch 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Rotate(float);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float _doorTargetYaw;
	float _doorInitialYaw;
	float _doorCurrentYaw;
	void Init();
};
