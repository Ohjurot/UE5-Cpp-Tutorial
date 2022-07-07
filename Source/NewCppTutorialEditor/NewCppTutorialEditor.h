#pragma once

#include "Engine.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"

#include "MoveComponentVisualizer.h"

DECLARE_LOG_CATEGORY_EXTERN(NewCppTutorialEditor, All, All)

class FNewCppTutorialEditorModule: public IModuleInterface
{
public:
    void StartupModule() override;
    void ShutdownModule() override;
};
