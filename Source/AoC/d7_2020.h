// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Misc/CString.h" // Atoi
#include "d7_2020.generated.h"

UCLASS()
class AOC_API Ad7_2020 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ad7_2020();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = Data, meta = (AllowPrivateAccess = "true"))
		class UDataTable* Input;

	static void challenge1(UDataTable *Input, int64 answer);
	static void challenge2(UDataTable *Input, int64 answer);

	static FString CreateTargetNameFromParsedArray(TArray<FString> SplitString);
	
};

USTRUCT(BlueprintType)
struct F2020d7Structure : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString container;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString target1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString target2;
};