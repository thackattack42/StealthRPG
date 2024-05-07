// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPG_Tutorial_SeriesGameMode.h"
#include "RPG_Tutorial_SeriesCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPG_Tutorial_SeriesGameMode::ARPG_Tutorial_SeriesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
