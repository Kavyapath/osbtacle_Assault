// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLESASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category="Moving ");
	FVector PlatformVelocity=FVector(100,0,0);

	
	UPROPERTY(EditAnywhere, Category = "Moving ");
	float MovedDistance = 100;
	
	FVector StartLocation;
	// for rotation
	UPROPERTY(EditAnywhere, Category = "Rotation");
	FRotator RotationVelocity;

 void MovePlatform(float DeltaTime) ;
 void RotatePlatform(float DeltaTime);
 bool ShouldPlatformReturn() const;//making function const means you cannot modify any vairable of class inside the function it is forced by the compiler and only those function which are const function only they can be called inside the const function 
 float GetDistanceMoved() const;


};
