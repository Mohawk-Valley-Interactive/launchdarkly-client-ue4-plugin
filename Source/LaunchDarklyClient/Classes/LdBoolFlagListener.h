#pragma once

#include "LdBoolFlagListener.generated.h"

UCLASS(EditInlineNew, BlueprintType)
class LAUNCHDARKLYCLIENT_API ULdBoolFlagListener : public UObject
{
	GENERATED_BODY()
public:
	ULdBoolFlagListener();
	void BeginDestroy() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLaunchDarkly_OnBoolFlagChangedDynamicDelegate, bool, FlagValue);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "On Bool Feature Flag Changed"))
	FLaunchDarkly_OnBoolFlagChangedDynamicDelegate OnBoolFlagChangedDynamicDelegate;

	void RegisterWithFlag(FString FlagName, bool DefaultVal);
	void ValueChanged();
	void ValueChanged(bool FlagValue);
private:
	bool IsRegistered = false;
	FString FlagName;
	bool DefaultVal;

	void Unregister();
};