// Fill out your copyright notice in the Description page of Project Settings.


#include "d1_1_2020.h"
#include "Engine/Engine.h"
#include "Containers/UnrealString.h"

// Sets default values
Ad1_1_2020::Ad1_1_2020()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ad1_1_2020::BeginPlay()
{
	Super::BeginPlay();

	Ad1_1_2020::challenge1();
	Ad1_1_2020::challenge2();
	
}

// Called every frame
void Ad1_1_2020::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Ad1_1_2020::challenge1()
{
	auto start = std::chrono::high_resolution_clock::now();
	FString ContextString;
	TArray<FName> RowNames = Input->GetRowNames();
	bool found = false;
	for (auto& sourceRowName : RowNames)
	{

		F2020d1Input* sourceRow = Input->FindRow<F2020d1Input>(sourceRowName, ContextString);
		if (sourceRow)
		{
			for (auto& targetRowName : RowNames)
			{
				F2020d1Input* targetRow = Input->FindRow<F2020d1Input>(targetRowName, ContextString);
				if (targetRow)
				{
					int32 sum = targetRow->input + sourceRow->input;
					if (sum == 2020)
					{
						FirstNumber = sourceRow->input;
						LastNumber = targetRow->input;
						break;
					}
				}
				else
				{
					UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad target row name : %s"), *targetRowName.ToString());
				}
			}
		}
		else
		{
			UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad source row name : %s"), *sourceRowName.ToString());
		}
		if (found)
		{
			break;
		}
	}
	answer = FirstNumber * LastNumber;
	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

void Ad1_1_2020::challenge2()
{
	auto start = std::chrono::high_resolution_clock::now();
	FString ContextString;
	TArray<FName> RowNames = Input->GetRowNames();
	bool found = false;
	int32 FirstIterator = 0;
	int32 MiddleIterator = 0;
	int32 LastIterator = 0;
	for (auto& FirstRowName : RowNames)
	{
		if (!(FirstIterator == MiddleIterator || FirstIterator == LastIterator))
		{
			F2020d1Input* FirstRow = Input->FindRow<F2020d1Input>(FirstRowName, ContextString);
			if (FirstRow)
			{
				MiddleIterator = 0;
				for (auto& MiddleRowName : RowNames)
				{
					if (!(FirstIterator == MiddleIterator || MiddleIterator == LastIterator))
					{
						F2020d1Input* MiddleRow = Input->FindRow<F2020d1Input>(MiddleRowName, ContextString);
						if (MiddleRow)
						{
							LastIterator = 0;
							for (auto& LastRowName : RowNames)
							{
								if (!(LastIterator == MiddleIterator || FirstIterator == LastIterator))
								{
									F2020d1Input* LastRow = Input->FindRow<F2020d1Input>(LastRowName, ContextString);
									if (LastRow)
									{
										int32 sum = LastRow->input + MiddleRow->input + FirstRow->input;
										if (sum == 2020)
										{
											FirstNumber = FirstRow->input;
											MiddleNumber = MiddleRow->input;
											LastNumber = LastRow->input;
											break;
										}
									}
									else
									{
										UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad middle row name : %s"), *LastRowName.ToString());
									}
								}
								LastIterator++;
							}

						}
						else
						{
							UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad middle row name : %s"), *MiddleRowName.ToString());
						}
					}
					if (found)
					{
						break;
					}
					MiddleIterator++;
				}
			}
			else
			{
				UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad first row name : %s"), *FirstRowName.ToString());
			}
		}
		if (found)
		{
			break;
		}
		FirstIterator++;
	}
	answer = FirstNumber * MiddleNumber * LastNumber;
	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}
