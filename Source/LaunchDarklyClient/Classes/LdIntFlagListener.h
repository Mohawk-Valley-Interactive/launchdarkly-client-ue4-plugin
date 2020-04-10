#pragma once

#include "LdIntFlagListener.generated.h"

UCLASS(EditInlineNew, BlueprintType)
class LAUNCHDARKLYCLIENT_API ULdIntFlagListener : public UObject
{
	GENERATED_BODY()
public:
	ULdIntFlagListener();
	void BeginDestroy() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLaunchDarkly_OnIntFlagChangedDynamicDelegate, int, FlagValue);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "On Int Feature Flag Changed"))
	FLaunchDarkly_OnIntFlagChangedDynamicDelegate OnIntFlagChangedDynamicDelegate;

	void RegisterWithFlag(FString FlagName, int DefaultVal);
	void ValueChanged();
	void ValueChanged(int FlagValue);
private:
	bool IsRegistered = false;
	FString FlagName;
	int DefaultVal;

	void Unregister();
};