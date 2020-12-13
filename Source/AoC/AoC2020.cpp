// Fill out your copyright notice in the Description page of Project Settings.


#include "AoC2020.h"

// Sets default values
AAoC2020::AAoC2020()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAoC2020::BeginPlay()
{
	Super::BeginPlay();
	TimeStart = std::chrono::high_resolution_clock::now();
	Ad7_2020::challenge1(Input, answer);
	
	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	TimeStop = std::chrono::high_resolution_clock::now();
	TimeDuration = std::chrono::duration_cast<std::chrono::microseconds>(TimeStop - TimeStart);
	TimeDurationInFloat = std::chrono::duration<float>(TimeDuration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), TimeDurationInFloat);
}

// Called every frame
void AAoC2020::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

