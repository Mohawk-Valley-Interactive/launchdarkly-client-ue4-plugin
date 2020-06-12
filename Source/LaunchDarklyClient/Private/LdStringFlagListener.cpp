#include "LdStringFlagListener.h"

#include "LaunchDarklyClient.h"

ULdStringFlagListener::ULdStringFlagListener()
{

}

void ULdStringFlagListener::BeginDestroy()
{
	Unregister();
	Super::BeginDestroy();
}

void ULdStringFlagListener::Unregister()
{
	if(!IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdStringFlagListener::UnregisterWithFlag() called for flag '%s' when not registered; call aborted."), *(this->FlagName));
		return;
	}

	OnStringFlagChangedDynamicDelegate.Clear();
	FLaunchDarklyClientModule::Get()->UnregisterStringFlagListener(this, FlagName);
}

void ULdStringFlagListener::RegisterWithFlag(FString FN, FString DV)
{
	if(IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdStringFlagListener::RegisterWithFlag() called for flag '%s' when already registered with '%s'; call aborted."), *(this->FlagName), *FlagName);
		return;
	}

	this->FlagName = FN;
	this->DefaultVal = DV;
	this->IsRegistered = true;

	FLaunchDarklyClientModule::Get()->RegisterStringFlagListener(this, FlagName);
}

void ULdStringFlagListener::ValueChanged()
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdBoolFlagListener::ValueChanged() called for flag '%s'."), *(this->FlagName));
	OnStringFlagChangedDynamicDelegate.Broadcast(FLaunchDarklyClientModule::Get()->GetStringVariation(FlagName, DefaultVal));
}

void ULdStringFlagListener::ValueChanged(FString FlagValue)
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdBoolFlagListener::ValueChanged(...) called for flag '%s'."), *(this->FlagName));
	OnStringFlagChangedDynamicDelegate.Broadcast(FlagValue);
}