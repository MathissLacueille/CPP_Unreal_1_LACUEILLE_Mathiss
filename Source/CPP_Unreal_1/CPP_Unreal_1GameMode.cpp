// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPP_Unreal_1GameMode.h"
#include "CPP_Unreal_1Character.h"
#include "UObject/ConstructorHelpers.h"

ACPP_Unreal_1GameMode::ACPP_Unreal_1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
