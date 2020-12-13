// Fill out your copyright notice in the Description page of Project Settings.


#include "d7_2020.h"

// Sets default values
Ad7_2020::Ad7_2020()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ad7_2020::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Ad7_2020::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Ad7_2020::challenge1(UDataTable *Input, int64 answer)
{
	TArray<FName> RowNames = Input->GetRowNames();
	TMap<FString, TMap<FString, int32>> Catalogue;
	FString ContextString;

	for (FName RowName : RowNames)
	{
		F2020d7Structure* row = Input->FindRow<F2020d7Structure>(RowName, ContextString);
		TArray<FString> SplitString;
		TCHAR Delimiter = ' ';
		row->container.ParseIntoArray(SplitString, &Delimiter, true);
		//UE_LOG(LogCollision, Warning, TEXT("%s"), *SplitString[0]);
		FString ContainerName = SplitString[0] + SplitString[1];
		row->target1.ParseIntoArray(SplitString, &Delimiter, true);
		FString Target1Name = CreateTargetNameFromParsedArray(SplitString);
		int32 Target1Amount = FCString::Atoi(*SplitString[0]);
		TMap<FString, int32> Targets;
		Targets.Add(Target1Name, Target1Amount);
		if (!row->target2.IsEmpty())
		{
			row->target2.ParseIntoArray(SplitString, &Delimiter, true);
			FString Target2Name = CreateTargetNameFromParsedArray(SplitString);
			int32 Target2Amount = FCString::Atoi(*SplitString[0]);
			Targets.Add(Target2Name, Target2Amount);
		}
		Catalogue.Add(ContainerName, Targets);
	}

	for (auto Container : Catalogue)
	{
		for (auto target : Container)
		{

		}
	}
}

void Ad7_2020::challenge2(UDataTable *Input, int64 answer)
{
}

FString Ad7_2020::CreateTargetNameFromParsedArray(TArray<FString> SplitString)
{
	return SplitString[1] + SplitString[2];
}

