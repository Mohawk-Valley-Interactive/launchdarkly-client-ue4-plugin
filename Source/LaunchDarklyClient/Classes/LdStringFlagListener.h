#pragma once

#include "LdStringFlagListener.generated.h"

UCLASS(EditInlineNew, BlueprintType)
class LAUNCHDARKLYCLIENT_API ULdStringFlagListener : public UObject
{
	GENERATED_BODY()
public:
	ULdStringFlagListener();
	void BeginDestroy() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLaunchDarkly_OnStringFlagChangedDynamicDelegate, FString, FlagValue);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "On String Feature Flag Changed"))
	FLaunchDarkly_OnStringFlagChangedDynamicDelegate OnStringFlagChangedDynamicDelegate;

	void RegisterWithFlag(FString FlagName, FString DefaultVal);
	void ValueChanged();
	void ValueChanged(FString FlagValue);
private:
	bool IsRegistered = false;
	FString FlagName;
	FString DefaultVal;

	void Unregister();
};