// Fill out your copyright notice in the Description page of Project Settings.


#include "TestClass.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATestClass::ATestClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATestClass::MoveTowardsNearestPlayer(float IncrementLocation)
{
	FVector NearestPlayerLocation = GetNearestPlayerLocation();

	if (!NearestPlayerLocation.IsZero())
	{
		FVector CurrentLocation = GetActorLocation();
		FVector Direction = (NearestPlayerLocation - CurrentLocation).GetSafeNormal();

		SetActorLocation(CurrentLocation + Direction * IncrementLocation);
	}
}


FVector ATestClass::GetNearestPlayerLocation()
{
	TArray<AActor*> Players;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacter::StaticClass(), Players);


	FVector NearestLocation;
	float NearestDistance = FLT_MAX;

	for (AActor* Player : Players)
	{
		float Distance = FVector::Dist(GetActorLocation(), Player->GetActorLocation());
		if (Distance < NearestDistance)
		{
			NearestDistance = Distance;
			NearestLocation = Player->GetActorLocation();
		}
	}

	return NearestLocation;
}
void ATestClass::BeginPlay()
{
	Super::BeginPlay();
}


void ATestClass::Tick(float DeltaTime)
{
	GEngine->ClearOnScreenDebugMessages();
	Super::Tick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(-1, 0.1, FColor::Red, GetNearestPlayerLocation().ToString());
	
	MoveTowardsNearestPlayer(1.0f);

}

