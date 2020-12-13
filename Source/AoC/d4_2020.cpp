// Fill out your copyright notice in the Description page of Project Settings.


#include "d4_2020.h"

// Sets default values
Ad4_2020::Ad4_2020()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void Ad4_2020::challenge1()
{
	auto start = std::chrono::high_resolution_clock::now();

	TArray<FName> RowNames = Input->GetRowNames();

    answer = 0;
	for (auto RowName : RowNames)
	{
        TMap<FString, FString> Passport;
        F2020d4Structure* row = Input->FindRow<F2020d4Structure>(RowName, ContextString);

        if (row->key1 != "")
        {
            Passport.Add(row->key1, row->value1);
        }
        if (row->key2 != "")
        {
            Passport.Add(row->key2, row->value2);
        }
        if (row->key3 != "")
        {
            Passport.Add(row->key3, row->value3);
        }
        if (row->key4 != "")
        {
            Passport.Add(row->key4, row->value4);
        }
        if (row->key5 != "")
        {
            Passport.Add(row->key5, row->value5);
        }
        if (row->key6 != "")
        {
            Passport.Add(row->key6, row->value6);
        }
        if (row->key7 != "")
        {
            Passport.Add(row->key7, row->value7);
        }
        if (row->key8 != "")
        {
            Passport.Add(row->key8, row->value8);
        }
        if (Passport.Num() == 8 || (Passport.Num() == 7 && !Passport.Contains("cid")))
        {
            answer++;
        }
	}
    UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);
    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    float time = std::chrono::duration<float>(duration).count();
    UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

void Ad4_2020::challenge2()
{
    auto start = std::chrono::high_resolution_clock::now();

    TArray<FName> RowNames = Input->GetRowNames();

    answer = 0;
    for (auto RowName : RowNames)
    {
        //UE_LOG(LogCollision, Warning, TEXT("row : %s"), *RowName.ToString());
        TMap<FString, FString> Passport;
        F2020d4Structure* row = Input->FindRow<F2020d4Structure>(RowName, ContextString);

        if (row->key1 != "")
        {
            Passport.Add(row->key1, row->value1);
        }
        if (row->key2 != "")
        {
            Passport.Add(row->key2, row->value2);
        }
        if (row->key3 != "")
        {
            Passport.Add(row->key3, row->value3);
        }
        if (row->key4 != "")
        {
            Passport.Add(row->key4, row->value4);
        }
        if (row->key5 != "")
        {
            Passport.Add(row->key5, row->value5);
        }
        if (row->key6 != "")
        {
            Passport.Add(row->key6, row->value6);
        }
        if (row->key7 != "")
        {
            Passport.Add(row->key7, row->value7);
        }
        if (row->key8 != "")
        {
            Passport.Add(row->key8, row->value8);
        }
        bool isValid = true;
        if (Passport.Num() == 8 || (Passport.Num() == 7 && !Passport.Contains("cid")))
        {
            if (Passport.Contains("byr"))
            {
                int32 byr = FCString::Atoi(*Passport["byr"]);
                if (!(byr >= 1920 && byr <= 2002))
                {
                    isValid = false;
                    //UE_LOG(LogCollision, Warning, TEXT("byr : %d"), byr);
                }
            }
            if (Passport.Contains("iyr") && isValid)
            {
                int32 iyr = FCString::Atoi(*Passport["iyr"]);
                if (!(iyr >= 2010 && iyr <= 2020))
                {
                    isValid = false;
                    //UE_LOG(LogCollision, Warning, TEXT("iyr : %d"), iyr);
                }
            }
            if (Passport.Contains("eyr") && isValid)
            {
                int32 eyr = FCString::Atoi(*Passport["eyr"]);
                if (!(eyr >= 2020 && eyr <= 2030))
                {
                    isValid = false;
                    //UE_LOG(LogCollision, Warning, TEXT("eyr : %d"), eyr);
                }
            }
            if (Passport.Contains("hgt") && isValid)
            {
                FString Height = Passport["hgt"];
                int32 Length = Height.Len();

                FString Unit = "";
                Unit.AppendChar(Height[Length - 2]);
                Unit.AppendChar(Height[Length - 1]);
                FString HeightNumber = "";
                for (int32 i = 0; i < Length - 2; i++)
                {
                    HeightNumber.AppendChar(Height[i]);
                }
                int32 HeightInt = FCString::Atoi(*HeightNumber);
                if (Unit == "cm")
                {
                    if (!(HeightInt >= 150 && HeightInt <= 193))
                    {
                        isValid = false;
                        //UE_LOG(LogCollision, Warning, TEXT("cm : %d"), HeightInt);
                    }
                }
                else if (Unit == "in")
                {
                    if (!(HeightInt >= 59 && HeightInt <= 76))
                    {
                        isValid = false;
                        //UE_LOG(LogCollision, Warning, TEXT("in : %d"), HeightInt);
                    }
                }
                else
                {
                    isValid = false;
                    //UE_LOG(LogCollision, Warning, TEXT("ERROR bad unit : %s"), *Unit);
                }
            }
            if (Passport.Contains("hcl") && isValid)
            {
                if (Passport["hcl"][0] == '#' && Passport["hcl"].Len() == 7)
                {
                    for (int32 i = 1; i < Passport["hcl"].Len(); i++)
                    {
                        if (!((Passport["hcl"][i] >= 48 && Passport["hcl"][i] <= 57) || (Passport["hcl"][i] >= 97 && Passport["hcl"][i] <= 102)))
                        {
                            isValid = false;
                            //UE_LOG(LogCollision, Warning, TEXT("hcl : %c"), Passport["hcl"][i]);
                        }
                    }
                }
                else
                {
                    isValid = false;
                    //UE_LOG(LogCollision, Warning, TEXT("hcl length : %d"), Passport["hcl"].Len());
                }
            }
            if (Passport.Contains("ecl") && isValid)
            {
                if ( !( Passport["ecl"] == "amb" || Passport["ecl"] == "blu" || Passport["ecl"] == "brn" || Passport["ecl"] == "gry" || Passport["ecl"] == "grn" || Passport["ecl"] == "hzl" || Passport["ecl"] == "oth") )
                {
                    isValid = false;
                    //UE_LOG(LogCollision, Warning, TEXT("ecl : %s"), *Passport["ecl"]);
                }
            }
            if (Passport.Contains("pid") && isValid)
            {
                if (Passport["pid"].Len() == 9)
                {
                    for (int32 i = 0; i < Passport["pid"].Len() || isValid == false; i++)
                    {
                        if ( !(Passport["pid"][i] >= 48 && Passport["pid"][i] <= 57))
                        {
                            isValid = false;
                            //UE_LOG(LogCollision, Warning, TEXT("pid : %c"), Passport["pid"][i]);
                        }
                    }
                }
                else
                {
                    isValid = false;
                    //UE_LOG(LogCollision, Warning, TEXT("pid length : %d"), Passport["pid"].Len());
                }
            }
        }
        else
        {
            isValid = false;
        }

        if (isValid == true)
        {
            answer++;
        }
    }
    UE_LOG(LogCollision, Warning, TEXT("ANSWER : %d"), answer);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    float time = std::chrono::duration<float>(duration).count();
    UE_LOG(LogCollision, Warning, TEXT("Time taken: %f s"), time);
}

// Called when the game starts or when spawned
void Ad4_2020::BeginPlay()
{
	Super::BeginPlay();
    Ad4_2020::challenge1();
    Ad4_2020::challenge2();
}

// Called every frame
void Ad4_2020::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

std::vector<int> Ad4_2020::split(std::string s, std::string delimiter)
{
    size_t pos = 0;
    std::string token;
    std::vector<int> Result;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        int nb = strtol(token.data(), nullptr, 10);
        Result.push_back(nb);
        s.erase(0, pos + delimiter.length());
    }
    int nb = strtol(s.data(), nullptr, 10);
    Result.push_back(nb);
    return Result;
}
