// Fill out your copyright notice in the Description page of Project Settings.


#include "d3_2020.h"

// Sets default values
Ad3_2020::Ad3_2020()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void Ad3_2020::challenge1()
{
	auto start = std::chrono::high_resolution_clock::now();

	int32 X = 0; //column
	int32 Y = 1; //row
	FName FirstRowName = "1";
	F2020d3Structure* FirstRow = Input->FindRow<F2020d3Structure>(FirstRowName, ContextString);
	FString FirstRowAsString = FirstRow->input;
	auto FirstRowAsChar = FirstRowAsString.GetCharArray();
	int32 Width = FirstRowAsChar.Num();
	bool first = true;
	
	answer = 0;

	TArray<FName> RowNames = Input->GetRowNames();
	for (auto RowName : RowNames)
	{
		if (first)
		{
			X = 0;
			first = false;
		}
		else
		{
			X += 3;
			X %= Width-1;
			F2020d3Structure* row = Input->FindRow<F2020d3Structure>(RowName, ContextString);
			FString StringRow = row->input;
			auto CharRow = StringRow.GetCharArray();
			if (CharRow[X] == '#')
			{
				answer++;
			}
		}
	}

	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

void Ad3_2020::challenge2()
{
	auto start = std::chrono::high_resolution_clock::now();

	int32 X = 0; //column
	int32 Y = 1; //row
	FName FirstRowName = "1";
	F2020d3Structure* FirstRow = Input->FindRow<F2020d3Structure>(FirstRowName, ContextString);
	FString FirstRowAsString = FirstRow->input;
	auto FirstRowAsChar = FirstRowAsString.GetCharArray();
	int32 Width = FirstRowAsChar.Num();
	bool first = true;

	TArray<int32> XMovements = { 1,3,5,7,1 };
	TArray<int32> YMovements = { 1,1,1,1,2 };
	TArray<uint32> answers = { 0,0,0,0,0 };

	int32 iteration = 0;
	TArray<FName> RowNames = Input->GetRowNames();
	for (int32 XMovement : XMovements)
	{
		first = true;
		for (auto RowName : RowNames)
		{
			int32 RowNumber = FCString::Atoi(*RowName.ToString());
			if ((RowNumber-1) % YMovements[iteration] == 0)
			{
				if (first)
				{
					X = 0;
					first = false;
				}
				else
				{
					X += XMovements[iteration];
					X %= (Width - 1);
					F2020d3Structure* row = Input->FindRow<F2020d3Structure>(RowName, ContextString);
					FString StringRow = row->input;
					auto CharRow = StringRow.GetCharArray();
					if (CharRow[X] == '#')
					{
						answers[iteration]++;
					}
				}
			}
		}
		iteration++;
	}

	answer = 1;
	for (int32 number : answers)
	{
		answer *= number;
	}

	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %llu"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

// Called when the game starts or when spawned
void Ad3_2020::BeginPlay()
{
	Super::BeginPlay();
	
	Ad3_2020::challenge1();
	Ad3_2020::challenge2();
}

// Called every frame
void Ad3_2020::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

