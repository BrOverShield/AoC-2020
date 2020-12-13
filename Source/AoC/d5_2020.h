// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "chrono"
#include <math.h> // pow
#include "d5_2020.generated.h"

UCLASS()
class AOC_API Ad5_2020 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ad5_2020();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = Data, meta = (AllowPrivateAccess = "true"))
		class UDataTable* Input;

	int64 answer;
	FString ContextString;
	void challenge1();
	void challenge2();

};

USTRUCT(BlueprintType)
struct F2020d5Structure : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString input;
};