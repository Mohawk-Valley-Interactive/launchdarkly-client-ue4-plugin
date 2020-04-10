#pragma once

#include "LdFloatFlagListener.generated.h"

UCLASS(EditInlineNew, BlueprintType)
class LAUNCHDARKLYCLIENT_API ULdFloatFlagListener : public UObject
{
	GENERATED_BODY()
public:
	ULdFloatFlagListener();
	void BeginDestroy() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLaunchDarkly_OnFloatFlagChangedDynamicDelegate, float, FlagValue);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "On Float Feature Flag Changed"))
	FLaunchDarkly_OnFloatFlagChangedDynamicDelegate OnFloatFlagChangedDynamicDelegate;

	void RegisterWithFlag(FString FlagName, float DefaultVal);
	void ValueChanged();
	void ValueChanged(float FlagValue);
private:
	bool IsRegistered = false;
	FString FlagName;
	float DefaultVal;

	void Unregister();
};