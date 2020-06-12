#include "LdBoolFlagListener.h"

#include "LaunchDarklyClient.h"

ULdBoolFlagListener::ULdBoolFlagListener()
{

}

void ULdBoolFlagListener::BeginDestroy()
{
	Unregister();
	Super::BeginDestroy();
}

void ULdBoolFlagListener::Unregister()
{
	if(!IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdBoolFlagListener::UnregisterWithFlag() called for flag '%s' when not registered; call aborted."), *(this->FlagName));
		return;
	}

	OnBoolFlagChangedDynamicDelegate.Clear();
	FLaunchDarklyClientModule::Get()->UnregisterBoolFlagListener(this, FlagName);
}

void ULdBoolFlagListener::RegisterWithFlag(FString FN, bool DV)
{
	if(IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdBoolFlagListener::RegisterWithFlag() called for flag '%s' when already registered with '%s'; call aborted."), *(this->FlagName), *FlagName);
		return;
	}

	this->FlagName = FN;
	this->DefaultVal = DV;
	this->IsRegistered = true;

	FLaunchDarklyClientModule::Get()->RegisterBoolFlagListener(this, FlagName);
}

void ULdBoolFlagListener::ValueChanged()
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdBoolFlagListener::ValueChanged() called for flag '%s'."), *(this->FlagName));
	OnBoolFlagChangedDynamicDelegate.Broadcast(FLaunchDarklyClientModule::Get()->GetBoolVariation(FlagName, DefaultVal));
}

void ULdBoolFlagListener::ValueChanged(bool FlagValue)
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdBoolFlagListener::ValueChanged(...) called for flag '%s'."), *(this->FlagName));
	OnBoolFlagChangedDynamicDelegate.Broadcast(FlagValue);
}