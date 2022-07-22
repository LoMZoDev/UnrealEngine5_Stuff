// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	//On Beginplay set the variable " PlatformStartLocation" to its current location as placed in the world.
	PlatformStartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//Platform Current Location or PCL is set in the headerfile 
	
	//Set PCL's current location in the world
	FVector PlatformCurrentLocation = GetActorLocation();
	//Have PCL move with "Delta Time" or game ticks as well as the editable variable PlatformVelocity
	PlatformCurrentLocation = PlatformCurrentLocation + (DeltaTime * PlatformVelocity);

	//Update PCL's location every tick based on the line above
	SetActorLocation(PlatformCurrentLocation);

	//LOCAL VARIABLE Distance Moved is to keep track of it in the code not the editor as no UPROPERTY tag is present
	float DistanceMoved = FVector::Dist(PlatformStartLocation, PlatformCurrentLocation);
	
	if ( DistanceMoved > MoveDistance ) 
	{
		
		

		//Using the dot operator to get the normal of our velocity vector 
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();

		//Once the platform makes it to end make that end location the new start location and flip flop endlessly
		PlatformStartLocation = PlatformCurrentLocation +  MoveDistance;
		SetActorLocation(PlatformStartLocation);

		//By making it negative 'PV', We set it to the negative of the value entered for 'PV' entered in the editor
		PlatformVelocity = -PlatformVelocity;
	}
}
