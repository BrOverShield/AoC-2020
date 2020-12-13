// Fill out your copyright notice in the Description page of Project Settings.


#include "d6_2020.h"

// Sets default values
Ad6_2020::Ad6_2020()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ad6_2020::BeginPlay()
{
	Super::BeginPlay();
	Ad6_2020::challenge1();
	Ad6_2020::challenge2();
	
}

// Called every frame
void Ad6_2020::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Ad6_2020::challenge1()
{
	auto start = std::chrono::high_resolution_clock::now();

	TArray<FName> RowNames = Input->GetRowNames();
	answer = 0;
	FString GroupAnswers = "";
	int32 position;
	for (auto RowName : RowNames)
	{
		F2020d6Structure* row = Input->FindRow<F2020d6Structure>(RowName, ContextString);
		if (row->input == "")
		{
			answer += GroupAnswers.Len();
			//UE_LOG(LogCollision, Warning, TEXT("group : %d"), GroupAnswers.Len());
			GroupAnswers = "";
		}
		else
		{
			auto Answers = row->input.GetCharArray();
			for (TCHAR Answer : Answers)
			{
				if (!GroupAnswers.FindChar(Answer, position))
				{
					GroupAnswers += Answer;
				}
			}
			
		}
	}
	answer += GroupAnswers.Len();
	//UE_LOG(LogCollision, Warning, TEXT("group : %d"), GroupAnswers.Len());

	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

void Ad6_2020::challenge2()
{
	//3278 too high
	auto start = std::chrono::high_resolution_clock::now();

	TArray<FName> RowNames = Input->GetRowNames();
	bool first = true;
	FString stillStanding = "";
	FString Corrections = "";
	int32 Location;
	answer = 0;
	for (FName RowName : RowNames)
	{
		F2020d6Structure* row = Input->FindRow<F2020d6Structure>(RowName, ContextString);
		if (row->input == "")
		{
			Ad6_2020::AddToSum(stillStanding);
			first = true;
		}
		else if (first)
		{
			stillStanding = row->input;
			first = false;
		}
		else
		{
			Corrections = FString::FString(stillStanding);
			TArray<TCHAR> StillStandingCharacters = stillStanding.GetCharArray();
			for (TCHAR Character : StillStandingCharacters)
			{
				if (!row->input.Contains(&Character))
				{
					Corrections.FindChar(Character, Location);
					Corrections.RemoveAt(Location);
					//UE_LOG(LogCollision, Warning, TEXT("%s"), *Corrections);
				}
			}
			stillStanding = Corrections;
		}
	}
	Ad6_2020::AddToSum(stillStanding);

	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

void Ad6_2020::AddToSum(FString StillStanding)
{
	//UE_LOG(LogCollision, Warning, TEXT("%d | %s"), StillStanding.Len(), *StillStanding);
	answer += StillStanding.Len();
}

