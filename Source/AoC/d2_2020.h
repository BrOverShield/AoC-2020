// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/UnrealString.h"
#include "chrono"
#include "Engine/DataTable.h"
#include "d2_2020.generated.h"

UCLASS()
class AOC_API Ad2_2020 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ad2_2020();
	int32 answer;
	void challenge1();
	void challenge2();

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
struct F2020d2Structure : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 min;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 max;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString letter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString password;
};