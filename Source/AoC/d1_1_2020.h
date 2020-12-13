// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "iostream"
#include "time.h"
#include "chrono"
#include "Engine/DataTable.h"
#include "d1_1_2020.generated.h"

USTRUCT(BlueprintType)
struct F2020d1Input : public FTableRowBase
{
	GENERATED_BODY()
public:
	/** just A NUMBER **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 input;
};


UCLASS()
class AOC_API Ad1_1_2020 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ad1_1_2020();
	int32 FirstNumber;
	int32 MiddleNumber;
	int32 LastNumber;
	int32 answer;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = Data, meta = (AllowPrivateAccess = "true"))
		class UDataTable* Input;

	void challenge1();
	void challenge2();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};


