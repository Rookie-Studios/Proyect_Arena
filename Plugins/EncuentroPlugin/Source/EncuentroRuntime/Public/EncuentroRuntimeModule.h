#pragma once

#include "Modules/ModuleManager.h"

class FEncuentroRuntimeModule : public IModuleInterface
{
public:
	virtual void StartupModule() override {}
	virtual void ShutdownModule() override {}
};
