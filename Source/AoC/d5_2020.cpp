// Fill out your copyright notice in the Description page of Project Settings.


#include "d5_2020.h"

// Sets default values
Ad5_2020::Ad5_2020()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ad5_2020::BeginPlay()
{
	Super::BeginPlay();

	Ad5_2020::challenge1();
	Ad5_2020::challenge2();
	
}

// Called every frame
void Ad5_2020::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Ad5_2020::challenge1()
{
	auto start = std::chrono::high_resolution_clock::now();

	TArray<FName> RowNames = Input->GetRowNames();
	answer = 0;
	for (auto RowName : RowNames)
	{
		F2020d5Structure* row = Input->FindRow<F2020d5Structure>(RowName, ContextString);
		auto BinaryDirections = row->input.GetCharArray();
		int32 PlaneRow = 0;
		int32 PlaneColumn = 0;
		int32 SeatID = 0;
		int32 iteration = 0;
		for (auto Direction : BinaryDirections)
		{
			if (Direction == 'B')
			{
				PlaneRow += pow(2, 6 - iteration);
			}
			else if (Direction == 'R')
			{
				PlaneColumn += pow(2,2 - (iteration - 7));
			}
			else
			{
				if (!(Direction == 'F' || Direction == 'L' || Direction == '\0'))
				{
					UE_LOG(LogCollision, Warning, TEXT("ERROR bad direction : %c"), Direction);
				}
			}
			iteration++;
		}
		SeatID = PlaneRow * 8 + PlaneColumn;
		if (SeatID > answer)
		{
			answer = SeatID;
		}
	}

	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

void Ad5_2020::challenge2()
{
	auto start = std::chrono::high_resolution_clock::now();

	TArray<FName> RowNames = Input->GetRowNames();
	int32 Highest = 0;
	int32 Lowest = 1024;
	TMap<int32, int32> Seats;
	for (auto RowName : RowNames)
	{
		F2020d5Structure* row = Input->FindRow<F2020d5Structure>(RowName, ContextString);
		auto BinaryDirections = row->input.GetCharArray();
		int32 PlaneRow = 0;
		int32 PlaneColumn = 0;
		int32 SeatID = 0;
		int32 iteration = 0;
		for (auto Direction : BinaryDirections)
		{
			if (Direction == 'B')
			{
				PlaneRow += pow(2, 6 - iteration);
			}
			else if (Direction == 'R')
			{
				PlaneColumn += pow(2, 2 - (iteration - 7));
			}
			else
			{
				if (!(Direction == 'F' || Direction == 'L' || Direction == '\0'))
				{
					UE_LOG(LogCollision, Warning, TEXT("ERROR bad direction : %c"), Direction);
				}
			}
			iteration++;
		}
		SeatID = PlaneRow * 8 + PlaneColumn;
		Seats.Add(SeatID, SeatID);
		if (SeatID > Highest)
		{
			Highest = SeatID;
		}
		if (SeatID < Lowest)
		{
			Lowest = SeatID;
		}
	}

	for (int32 i = Lowest; i < Highest; i++)
	{
		if (!Seats.Contains(i))
		{
			answer = i;
			break;
		}
	}

	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

