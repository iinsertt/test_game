// Copyright Epic Games, Inc. All Rights Reserved.

#include "test1GameMode.h"
#include "test1Character.h"
#include "UObject/ConstructorHelpers.h"

Atest1GameMode::Atest1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
