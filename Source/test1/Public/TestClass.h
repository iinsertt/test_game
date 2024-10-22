// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestClass.generated.h"

UCLASS()
class TEST1_API ATestClass : public AActor
{
	GENERATED_BODY()
	FVector Location;
	
public:
	void MoveTowardsNearestPlayer(float IncrementLocation);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tranposition") int increment_location;
	// Sets default values for this actor's properties
	ATestClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	FVector GetNearestPlayerLocation();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
