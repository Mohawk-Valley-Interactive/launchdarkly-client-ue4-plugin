// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "LaunchDarklyClient.h"
#include "LaunchDarklyImpl.h"
#include "ISettingsModule.h"
#include "LaunchDarklySettings.h"

#define LOCTEXT_NAMESPACE "FLaunchDarklyClientModule"

DEFINE_LOG_CATEGORY(LaunchDarklyClient);

FLaunchDarklyClientModule* FLaunchDarklyClientModule::Instance = nullptr;
TSharedPtr<FLaunchDarklyImplBase> FLaunchDarklyClientModule::ModuleImpl = nullptr;

void FLaunchDarklyClientModule::StartupModule()
{
#if WITH_EDITOR
	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings(
			"Project", 
			"Plugins", 
			"LaunchDarkly", 
			LOCTEXT("RuntimeSettingsName", "LaunchDarkly"), 
			LOCTEXT("RuntimeSettingsDescription", "Configure the LaunchDarkly Client plugin."), 
			GetMutableDefault<ULaunchDarklySettings>());
	}
#endif
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	Instance = this;

#if(PLATFORM_ANDROID || PLATFORM_WINDOWS)
	ModuleImpl = MakeShareable(new FLaunchDarklyImpl());
#else
	ModuleImpl = MakeShareable(new FLaunchDarklyImplBase());
#endif

#if PLATFORM_ANDROID
	ModuleImpl->InitJavaFunctions();
#endif
}

void FLaunchDarklyClientModule::ShutdownModule()
{
#if WITH_EDITOR
	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings(
			"Project", 
			"Plugins", 
			"LaunchDarkly"
		);
	}
#endif
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	Instance = nullptr;
	ModuleImpl = nullptr;
}

TSharedPtr<FLaunchDarklyImplBase> FLaunchDarklyClientModule::Get()
{
	if(Instance == nullptr)
	{
		check(IsInGameThread());
		FModuleManager::LoadModuleChecked<FLaunchDarklyClientModule>("LaunchDarkly");
		// TODO Perhaps if we instead assign the output of the line above we can avoid exceptions in the check line that follows
		//Instance = FModuleManager::LoadModuleChecked<FLaunchDarklyClientModule>("LaunchDarkly");
	}

	check(Instance != nullptr);
	check(Instance->ModuleImpl.IsValid() == true);

	return Instance->ModuleImpl;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FLaunchDarklyClientModule, LaunchDarklyClient)