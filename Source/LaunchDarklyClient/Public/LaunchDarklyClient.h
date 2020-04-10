// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "LaunchDarklyImplBase.h"

DECLARE_LOG_CATEGORY_EXTERN(LaunchDarklyClient, Log, All);

class LAUNCHDARKLYCLIENT_API FLaunchDarklyClientModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static TSharedPtr<FLaunchDarklyImplBase> Get();

private:
	static FLaunchDarklyClientModule* Instance;
	static TSharedPtr<FLaunchDarklyImplBase> ModuleImpl;

};
