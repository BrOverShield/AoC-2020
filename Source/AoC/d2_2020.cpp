// Fill out your copyright notice in the Description page of Project Settings.


#include "d2_2020.h"

// Sets default values
Ad2_2020::Ad2_2020()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void Ad2_2020::challenge1()
{
	auto start = std::chrono::high_resolution_clock::now();

	FString ContextString;
	TArray<FName> RowNames = Input->GetRowNames();
	answer = 0;
	for (auto& RowName : RowNames)
	{
		F2020d2Structure* row = Input->FindRow<F2020d2Structure>(RowName, ContextString);
		if (row)
		{
			FString password = row->password;
			auto CharPassword = password.GetCharArray();
			int32 count = 0;
			for (auto Character : CharPassword)
			{
				//UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad target row name : %c"), Character);
				FString letter = row->letter;
				auto CharArrayLetter = letter.GetCharArray();
				TCHAR CharLetter = CharArrayLetter[0];
				if (Character == CharLetter)
				{
					count++;
				}
			}
			if (count >= row->min && count <= row->max)
			{
				answer++;
			}
		}
		else
		{
			UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad target row name : %s"), *RowName.ToString());
		}
	}

	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

void Ad2_2020::challenge2()
{
	auto start = std::chrono::high_resolution_clock::now();

	FString ContextString;
	TArray<FName> RowNames = Input->GetRowNames();
	answer = 0;
	for (auto& RowName : RowNames)
	{
		F2020d2Structure* row = Input->FindRow<F2020d2Structure>(RowName, ContextString);
		if (row)
		{
			FString password = row->password;
			auto CharPassword = password.GetCharArray();
			int32 NumberOfLetters = CharPassword.Num();
			//UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad target row name : %c"), Character);
			FString letter = row->letter;
			auto CharArrayLetter = letter.GetCharArray();
			TCHAR CharLetter = CharArrayLetter[0];
			int32 Position1 = row->min;
			int32 Position2 = row->max;
			Position1--;
			Position2--;
			if (Position1 <= NumberOfLetters - 1 && Position2 <= NumberOfLetters - 1)
			{
				if (CharPassword[Position1] == CharLetter)
				{
					if (CharPassword[Position2] != CharLetter)
					{
						answer++;
					}
				}
				else
				{
					if (CharPassword[Position2] == CharLetter)
					{
						answer++;
					}
				}
			}
			else
			{
				UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad index : position1 %d | position2 %d | length %d"), Position1, Position2, NumberOfLetters);
			}
		}
		else
		{
			UE_LOG(LogCollision, Warning, TEXT("ERROR : Bad target row name : %s"), *RowName.ToString());
		}
	}

	UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	float time = std::chrono::duration<float>(duration).count();
	UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

// Called when the game starts or when spawned
void Ad2_2020::BeginPlay()
{
	Super::BeginPlay();

	Ad2_2020::challenge1();
	Ad2_2020::challenge2();
	
}

// Called every frame
void Ad2_2020::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

