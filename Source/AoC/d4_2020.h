// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "chrono"
#include "string"
#include "vector"
#include "d4_2020.generated.h"

UCLASS()
class AOC_API Ad4_2020 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ad4_2020();
	int64 answer;
	FString ContextString;
	void challenge1();
	void challenge2();
	std::vector<int> split(std::string s, std::string delimiter);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category = Data, meta = (AllowPrivateAccess = "true"))
		class UDataTable* Input;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

USTRUCT(BlueprintType)
struct F2020d4Structure : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString key1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString value1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString key2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString value2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString key3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString value3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString key4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString value4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString key5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString value5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString key6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString value6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString key7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString value7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString key8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString value8;
};