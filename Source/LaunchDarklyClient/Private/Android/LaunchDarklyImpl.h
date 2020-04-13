#pragma once

#include "LaunchDarklyImplBase.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// ANDROID /////////////////////////////////////////////////////////////////////////////////////////
class LAUNCHDARKLYCLIENT_API FLaunchDarklyImpl : public FLaunchDarklyImplBase
{
public:
	static TMap<FString, TArray<ULdBoolFlagListener*>> BoolFlagListeners;
	static TMap<FString, TArray<ULdFloatFlagListener*>> FloatFlagListeners;
	static TMap<FString, TArray<ULdIntFlagListener*>> IntFlagListeners;
	static TMap<FString, TArray<ULdJsonFlagListener*>> JsonFlagListeners;
	static TMap<FString, TArray<ULdStringFlagListener*>> StringFlagListeners;

	~FLaunchDarklyImpl() override {}

	void InitJavaFunctions() override;

	////////////////////////////////////////////////////////////////////////////////////////////////
	// CLIENT STATE ////////////////////////////////////////////////////////////////////////////////
	bool InitializeClient(ULdConfigObject* LdConfig, ULdUserObject* LdUserObject, int ConnectionTimeoutMillis) override;

	void ShutdownClient() override;

	bool IsInitialized() override;

	bool IsOffline() override;

	void SetOffline() override;

	void SetOnline() override;

	////////////////////////////////////////////////////////////////////////////////////////////////
	// USER ATTRIBUTES /////////////////////////////////////////////////////////////////////////////
	void RefreshUserAttributes(ULdUserObject* LdUserObject) override;

	////////////////////////////////////////////////////////////////////////////////////////////////
	// VARIATIONS //////////////////////////////////////////////////////////////////////////////////
	bool GetBoolVariation(FString FlagName, bool DefaultValue) override;

	float GetFloatVariation(FString FlagName, float DefaultValue) override;

	int GetIntVariation(FString FlagName, int DefaultValue) override;

	TSharedPtr<FJsonObject> GetJsonVariation(FString FlagName, TSharedPtr<FJsonObject> DefaultValue) override;

	FString GetStringVariation(FString FlagName, FString DefaultValue) override;

	void RegisterBoolFlagListener(ULdBoolFlagListener* FlagListener, FString FlagName) override;

	void UnregisterBoolFlagListener(ULdBoolFlagListener* FlagListener, FString FlagName) override;

	void RegisterFloatFlagListener(ULdFloatFlagListener* FlagListener, FString FlagName) override;

	void UnregisterFloatFlagListener(ULdFloatFlagListener* FlagListener, FString FlagName) override;

	void RegisterIntFlagListener(ULdIntFlagListener* FlagListener, FString FlagName) override;

	void UnregisterIntFlagListener(ULdIntFlagListener* FlagListener, FString FlagName) override;

	void RegisterJsonFlagListener(ULdJsonFlagListener* FlagListener, FString FlagName) override;

	void UnregisterJsonFlagListener(ULdJsonFlagListener* FlagListener, FString FlagName) override;

	void RegisterStringFlagListener(ULdStringFlagListener* FlagListener, FString FlagName) override;

	void UnregisterStringFlagListener(ULdStringFlagListener* FlagListener, FString FlagName) override;

	////////////////////////////////////////////////////////////////////////////////////////////////
	// METRIC TRACKING /////////////////////////////////////////////////////////////////////////////
	void Track(FString MetricName) override;

	void Track(FString MetricName, TSharedPtr<FJsonObject> Data) override;

};