// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "d7_2020.h"
#include "chrono"
#include "AoC2020.generated.h"

UCLASS()
class AOC_API AAoC2020 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAoC2020();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	std::chrono::steady_clock::time_point TimeStart;
	std::chrono::steady_clock::time_point TimeStop;
	std::chrono::microseconds TimeDuration;
	float TimeDurationInFloat;
	int64 answer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = Data, meta = (AllowPrivateAccess = "true"))
		class UDataTable* Input;

};
