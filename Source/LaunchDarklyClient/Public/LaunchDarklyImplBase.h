#pragma once

#include "CoreMinimal.h"

class FJsonObject;
class ULdConfigObject;
class ULdBoolFlagListener;
class ULdFloatFlagListener;
class ULdIntFlagListener;
class ULdJsonFlagListener;
class ULdStringFlagListener;
class ULdUserObject;

class LAUNCHDARKLYCLIENT_API FLaunchDarklyImplBase
{
public:
	virtual ~FLaunchDarklyImplBase() {}

	////////////////////////////////////////////////////////////////////////////////////////////////
	// CLIENT STATE ////////////////////////////////////////////////////////////////////////////////
	virtual bool InitializeClient(ULdConfigObject* LdConfig, ULdUserObject* LdUser, int ConnectionTimeoutMillis);

	virtual void ShutdownClient();

	virtual bool IsInitialized();

	virtual bool IsOffline();

	virtual void SetOffline();

	virtual void SetOnline();

	////////////////////////////////////////////////////////////////////////////////////////////////
	// USER ATTRIBUTES /////////////////////////////////////////////////////////////////////////////
	virtual void RefreshUserAttributes(ULdUserObject* LdUserObject);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// VARIATIONS //////////////////////////////////////////////////////////////////////////////////
	virtual bool GetBoolVariation(FString FlagName, bool DefaultValue);

	virtual float GetFloatVariation(FString FlagName, float DefaultValue);

	virtual int GetIntVariation(FString FlagName, int DefaultValue);

	virtual TSharedPtr<FJsonObject> GetJsonVariation(FString FlagName, TSharedPtr<FJsonObject> DefaultValue);

	virtual FString GetStringVariation(FString FlagName, FString DefaultValue);

	virtual void RegisterBoolFlagListener(ULdBoolFlagListener* FlagListener, FString FlagName);

	virtual void UnregisterBoolFlagListener(ULdBoolFlagListener* FlagListener, FString FlagName);

	virtual void RegisterFloatFlagListener(ULdFloatFlagListener* FlagListener, FString FlagName);

	virtual void UnregisterFloatFlagListener(ULdFloatFlagListener* FlagListener, FString FlagName);

	virtual void RegisterIntFlagListener(ULdIntFlagListener* FlagListener, FString FlagName);

	virtual void UnregisterIntFlagListener(ULdIntFlagListener* FlagListener, FString FlagName);

	virtual void RegisterJsonFlagListener(ULdJsonFlagListener* FlagListener, FString FlagName);

	virtual void UnregisterJsonFlagListener(ULdJsonFlagListener* FlagListener, FString FlagName);

	virtual void RegisterStringFlagListener(ULdStringFlagListener* FlagListener, FString FlagName);

	virtual void UnregisterStringFlagListener(ULdStringFlagListener* FlagListener, FString FlagName);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// METRIC TRACKING /////////////////////////////////////////////////////////////////////////////
	virtual void Track(FString MetricName);

	virtual void Track(FString MetricName, TSharedPtr<FJsonObject> Data);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// ANDROID SPECIFIC ////////////////////////////////////////////////////////////////////////////
	virtual void InitJavaFunctions();
};