#pragma once

#include "LdJsonFlagListener.generated.h"

class ULdNodeObject;

UCLASS(EditInlineNew, BlueprintType)
class LAUNCHDARKLYCLIENT_API ULdJsonFlagListener : public UObject
{
	GENERATED_BODY()
public:
	ULdJsonFlagListener();
	void BeginDestroy() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLaunchDarkly_OnJsonFlagChangedDynamicDelegate, ULdNodeObject*, FlagValue);
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "On JSON Feature Flag Changed"))
	FLaunchDarkly_OnJsonFlagChangedDynamicDelegate OnJsonFlagChangedDynamicDelegate;

	void RegisterWithFlag(FString FlagName, ULdNodeObject* DefaultVal);
	void ValueChanged();
	void ValueChanged(ULdNodeObject* FlagValue);
private:
	bool IsRegistered = false;
	FString FlagName;
	ULdNodeObject* DefaultVal;

	void Unregister();
};