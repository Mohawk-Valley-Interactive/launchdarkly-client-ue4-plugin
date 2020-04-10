#pragma once

#include "LaunchDarklySettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class LAUNCHDARKLYCLIENT_API ULaunchDarklySettings : public UObject
{
	GENERATED_BODY()

public:
	ULaunchDarklySettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(Config, EditAnywhere, Category = "Basic", meta = (DisplayName = "Enable LaunchDarkly Client Debug Logging"))
	bool IsLoggingEnabled;
};
