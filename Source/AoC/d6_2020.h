// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "chrono"
#include "string"
#include "d6_2020.generated.h"

UCLASS()
class AOC_API Ad6_2020 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ad6_2020();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = Data, meta = (AllowPrivateAccess = "true"))
		class UDataTable* Input;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = Data, meta = (AllowPrivateAccess = "true"))
		//class UDataTable* InputAnswers;

	int64 answer;
	FString ContextString;
	FString ContextString2;
	void challenge1();
	void challenge2();
	void AddToSum(FString StillStanding);

};

USTRUCT(BlueprintType)
struct F2020d6Structure : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString input;
};

USTRUCT(BlueprintType)
struct F2020d6RStructure : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 input;
};