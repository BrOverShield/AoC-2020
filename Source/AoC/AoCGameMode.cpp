// Copyright Epic Games, Inc. All Rights Reserved.

#include "AoCGameMode.h"
#include "AoCHUD.h"
#include "AoCCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAoCGameMode::AAoCGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAoCHUD::StaticClass();
}
