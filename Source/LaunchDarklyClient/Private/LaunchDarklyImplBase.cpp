#include "LaunchDarklyImplBase.h"

#include "Dom/JsonObject.h"
#include "Engine/Engine.h"

#include "LdConfigObject.h"

#include "LaunchDarklyHelpers.h"

TMap<FString, TArray<ULdBoolFlagListener*>>& FLaunchDarklyImplBase::GetBoolFlagListeners()
{
	return BoolFlagListeners;
}

TMap<FString, TArray<ULdFloatFlagListener*>>& FLaunchDarklyImplBase::GetFloatFlagListeners()
{
	return FloatFlagListeners;
}

TMap<FString, TArray<ULdIntFlagListener*>>& FLaunchDarklyImplBase::GetIntFlagListeners()
{
	return IntFlagListeners;
}

TMap<FString, TArray<ULdJsonFlagListener*>>& FLaunchDarklyImplBase::GetJsonFlagListeners()
{
	return JsonFlagListeners;
}

TMap<FString, TArray<ULdStringFlagListener*>>& FLaunchDarklyImplBase::GetStringFlagListeners()
{
	return StringFlagListeners;
}

void FLaunchDarklyImplBase::InitJavaFunctions()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("CALLED BUT UNSUPPORTED: LaunchDarkly Plugin Java functions initialized from Generic Platform."));
}

bool FLaunchDarklyImplBase::InitializeClient(ULdConfigObject* LdConfigULd, ULdUserObject* LdUserObject, int ConnectionTimeoutMillis)
{
	FString DebugMessage = FString::Printf(TEXT("CALLED BUT UNSUPPORTED: LaunchDarkly client initialization called."));
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);

	return true;
}

void FLaunchDarklyImplBase::ShutdownClient()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("CALLED BUT UNSUPPORTED: LaunchDarkly client shutdown called."));
}

bool FLaunchDarklyImplBase::IsInitialized()
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY ISINITIALIZED CALLED ON UNSUPPORTED PLATFORM; RETURNING FALSE"));
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);

	return false;
}

bool FLaunchDarklyImplBase::IsOffline()
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY ISOFFLINE CALLED ON UNSUPPORTED PLATFORM; RETURNING TRUE."));
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);

	return true;
}

void FLaunchDarklyImplBase::SetOffline()
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY SETOFFLINE CALLED ON UNSUPPORTED PLATFORM."));
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::SetOnline()
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY SETONLINE CALLED ON UNSUPPORTED PLATFORM."));
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::RefreshUserAttributes(ULdUserObject* LdUserObject)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY REFRESHUSERATTRIBUTES CALLED ON UNSUPPORTED PLATFORM."));
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

bool FLaunchDarklyImplBase::GetBoolVariation(FString FlagName, bool DefaultValue)
{
	FString DebugMessage = FString::Printf(
		TEXT("LAUNCHDARKLY GETBOOLVARIATION CALLED ON UNSUPPORTED PLATFORM; RETURNING DEFAULT %s."), 
		DefaultValue ? TEXT("TRUE"): TEXT("FALSE")
	);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);

	return DefaultValue;
}

float FLaunchDarklyImplBase::GetFloatVariation(FString FlagName, float DefaultValue)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY GETDOUBLEVARIATION CALLED ON UNSUPPORTED PLATFORM; RETURNING DEFAULT %f."), DefaultValue);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);

	return DefaultValue;
}

int FLaunchDarklyImplBase::GetIntVariation(FString FlagName, int DefaultValue)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY GETINTVARIATION CALLED ON UNSUPPORTED PLATFORM; RETURNING DEFAULT %d."), DefaultValue);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);

	return DefaultValue;
}

TSharedPtr<FJsonObject> FLaunchDarklyImplBase::GetJsonVariation(FString FlagName, TSharedPtr<FJsonObject> DefaultValue)
{
	FString DefaultAsString = ULaunchDarklyHelpers::JsonObjectToString(DefaultValue);
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY GETJSONVARIATION CALLED ON UNSUPPORTED PLATFORM; RETURNING DEFAULT %s."), *DefaultAsString);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);

	return DefaultValue;
}

FString FLaunchDarklyImplBase::GetStringVariation(FString FlagName, FString DefaultValue)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY GETSTRINGVARIATION CALLED ON UNSUPPORTED PLATFORM; RETURNING DEFAULT %s."), *DefaultValue);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);

	return DefaultValue;
}

void FLaunchDarklyImplBase::RegisterBoolFlagListener(ULdBoolFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY REGISTERBOOLFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::UnregisterBoolFlagListener(ULdBoolFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY UNREGISTERBOOLFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::RegisterFloatFlagListener(ULdFloatFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY REGISTERFLOATFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::UnregisterFloatFlagListener(ULdFloatFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY UNREGISTERFLOATFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::RegisterIntFlagListener(ULdIntFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY REGISTERINTFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::UnregisterIntFlagListener(ULdIntFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY UNREGISTERINTFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::RegisterJsonFlagListener(ULdJsonFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY REGISTERJSONFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::UnregisterJsonFlagListener(ULdJsonFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY UNREGISTERJSONFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::RegisterStringFlagListener(ULdStringFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY REGISTERSTRINGFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::UnregisterStringFlagListener(ULdStringFlagListener* FlagListener, FString FlagName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY UNREGISTERSTRINGFLAGLISTENER CALLED ON UNSUPPORTED PLATFORM: FlagName: %s"), *FlagName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::Track(FString MetricName)
{
	FString DebugMessage = FString::Printf(TEXT("LAUNCHDARKLY TRACK CALLED ON UNSUPPORTED PLATFORM: Metric name: %s"), *MetricName);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
}

void FLaunchDarklyImplBase::Track(FString MetricName, TSharedPtr<FJsonObject> Data)
{
	FString DataAsString = ULaunchDarklyHelpers::JsonObjectToString(Data);
	FString DebugMessage = FString::Printf(
		TEXT("LAUNCHDARKLY TRACK CALLED ON UNSUPPORTED PLATFORM: Metric name: %s - Default value: %s"), *MetricName, *DataAsString
	);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage);
} 

void FLaunchDarklyImplBase::ResetListeners()
{
	for(auto& Entry : BoolFlagListeners)
	{
		TArray<ULdBoolFlagListener*>& Listeners = Entry.Value;
		for(auto& Listener : Listeners)
		{
			Listener->RemoveFromRoot();
		}
		Listeners.Empty();
	}
	BoolFlagListeners.Empty();

	for(auto& Entry : FloatFlagListeners)
	{
		TArray<ULdFloatFlagListener*>& Listeners = Entry.Value;
		for(auto& Listener : Listeners)
		{
			Listener->RemoveFromRoot();
		}
		Listeners.Empty();
	}
	FloatFlagListeners.Empty();

	for(auto& Entry : IntFlagListeners)
	{
		TArray<ULdIntFlagListener*>& Listeners = Entry.Value;
		for(auto& Listener : Listeners)
		{
			Listener->RemoveFromRoot();
		}
		Listeners.Empty();
	}
	IntFlagListeners.Empty();

	for(auto& Entry : JsonFlagListeners)
	{
		TArray<ULdJsonFlagListener*>& Listeners = Entry.Value;
		for(auto& Listener : Listeners)
		{
			Listener->RemoveFromRoot();
		}
		Listeners.Empty();
	}
	JsonFlagListeners.Empty();

	for(auto& Entry : StringFlagListeners)
	{
		TArray<ULdStringFlagListener*>& Listeners = Entry.Value;
		for(auto& Listener : Listeners)
		{
			Listener->RemoveFromRoot();
		}
		Listeners.Empty();
	}
	StringFlagListeners.Empty();
}