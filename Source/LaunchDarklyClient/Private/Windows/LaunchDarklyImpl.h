#pragma once

#include "LaunchDarklyImplBase.h"

#include "ldapi.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// WINDOWS /////////////////////////////////////////////////////////////////////////////////////////
class LAUNCHDARKLYCLIENT_API FLaunchDarklyImpl : public FLaunchDarklyImplBase
{
public:
	~FLaunchDarklyImpl() override {}

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

	void RegisterIntFlagListener(ULdIntFlagListener* FlagListener, FString FlagName) override;

	void UnregisterIntFlagListener(ULdIntFlagListener* FlagListener, FString FlagName) override;

	void RegisterFloatFlagListener(ULdFloatFlagListener* FlagListener, FString FlagName) override;

	void UnregisterFloatFlagListener(ULdFloatFlagListener* FlagListener, FString FlagName) override;

	void RegisterJsonFlagListener(ULdJsonFlagListener* FlagListener, FString FlagName) override;

	void UnregisterJsonFlagListener(ULdJsonFlagListener* FlagListener, FString FlagName) override;

	void RegisterStringFlagListener(ULdStringFlagListener* FlagListener, FString FlagName) override;

	void UnregisterStringFlagListener(ULdStringFlagListener* FlagListener, FString FlagName) override;

	////////////////////////////////////////////////////////////////////////////////////////////////
	// METRIC TRACKING /////////////////////////////////////////////////////////////////////////////
	void Track(FString MetricName) override;

	void Track(FString MetricName, TSharedPtr<FJsonObject> Data) override;

protected:
	// Static all the things that need to live in the two worlds of LD and UE4 Game threads.
	static LDClient_i* LdClient;

	static TMap<FString, TArray<ULdBoolFlagListener*>> BoolFlagListeners;
	static TMap<FString, TArray<ULdFloatFlagListener*>> FloatFlagListeners;
	static TMap<FString, TArray<ULdIntFlagListener*>> IntFlagListeners;
	static TMap<FString, TArray<ULdJsonFlagListener*>> JsonFlagListeners;
	static TMap<FString, TArray<ULdStringFlagListener*>> StringFlagListeners;

	static void BoolFlagListener(const char* const FlagName, const int FlagStatus);
	static void FloatFlagListener(const char* const FlagName, const int FlagStatus);
	static void IntFlagListener(const char* const FlagName, const int FlagStatus);
	static void JsonFlagListener(const char* const FlagName, const int FlagStatus);
	static void StringFlagListener(const char* const FlagName, const int FlagStatus);

	static void LdLogger(const char* s);
	static void ClientStatusCallback(int s);

	static void RestoreFlagListeners();
	static void UpdateAllFlagListeners();
};