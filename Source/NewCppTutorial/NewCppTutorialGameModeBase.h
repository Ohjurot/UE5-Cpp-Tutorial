// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"

#include "XPCharacter.h"

#include "NewCppTutorialGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class NEWCPPTUTORIAL_API ANewCppTutorialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void InitGameState() override;

private:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<AXPCharacter> CustomXPCharacterClass = AXPCharacter::StaticClass();
};
