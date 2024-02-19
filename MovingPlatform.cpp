// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values()
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT(" Begin play: %S"), *Name);

	

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*FVector LocalVector=MyVector;

	LocalVector.Z=LocalVector.Z+100;
	MyVector.Y=MyVector.Y+1;
	SetActorLocation(LocalVector);*/


	//Moving platform forward 
	//getting current loacation
	MovePlatform(DeltaTime);
	RotatePlatform( DeltaTime);
	
}
void AMovingPlatform::MovePlatform(float DeltaTime) {
	


	//reverse direction of motion

	if (ShouldPlatformReturn()) {
		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();//finding the normal vector of platform velocity direction
		StartLocation = StartLocation + (MoveDirection * MovedDistance);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;


	}
	else {
		FVector CurrentLocation = GetActorLocation();
		//add vector to the loaction 
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);//delta rime is how long each frame took to execute,and if we multiplying any object with delta time we are making our game frame independent 
		//set the location
		SetActorLocation(CurrentLocation);
	}


}
void AMovingPlatform::RotatePlatform(float DeltaTime) 
{
	//one way of rotation
	/*
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	SetActorRotation(CurrentRotation);*/

	//another better way
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}
bool AMovingPlatform::ShouldPlatformReturn() const
{
	 //replace DistanceMoved GetDistanceMoved function 
	return GetDistanceMoved() > MovedDistance;
}
float AMovingPlatform::GetDistanceMoved() const 
{
	return  FVector::Dist(StartLocation, GetActorLocation());//for finding the distance moved by the actor it will find the difference between x,y,z of the vector startlocation and the getactorLocation variable
}

