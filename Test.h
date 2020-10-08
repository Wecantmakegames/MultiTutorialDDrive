// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Test.generated.h"

/**
 * 
 */
UCLASS()
class MULTITUTORIAL_API ATest : public ATriggerVolume
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	FVector Test = FVector(-290.f, 0.f, 1784.f);
public:
	ATest();
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere)
		class AActor* SpecificActor;
};
