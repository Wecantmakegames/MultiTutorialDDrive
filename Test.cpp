// Fill out your copyright notice in the Description page of Project Settings.


#include "Test.h"
#include "Engine/World.h"
#include "GameFramework/GameModeBase.h"
#include "DrawDebugHelpers.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))


ATest::ATest() {
	OnActorBeginOverlap.AddDynamic(this, &ATest::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ATest::OnOverlapEnd);

}
void ATest::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)

{
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor enters trigger volume
		//print("Overlap Begin");
		//printFString("Other Actor = %s", *OtherActor->GetName());
		//OtherActor->SetActorLocation(GetWorld()->GetAuthGameMode()->GetSpawnLocation(), false, NULL, ETeleportType::ResetPhysics);
		OtherActor->Destroy();
		//if(OverlappedActor->HasAuthority())
		if (!ensure(GetWorld()->GetAuthGameMode() != nullptr)) return;
		GetWorld()->GetAuthGameMode()->RestartPlayer(GetWorld()->GetFirstPlayerController());
		//	->GetAuthGameMode()->RestartPlayer(GetWorld()->GetFirstPlayerController());
	}

}


void ATest::OnOverlapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OtherActor && (OtherActor != this)) {

		// print to screen using above defined method when actor leaves trigger volume
		print("Overlap Ended");
		printFString("%s has left the Trigger Volume", *OtherActor->GetName());

	}
}
void ATest::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 100, FColor::Cyan, true, -1, 0, 5);

}