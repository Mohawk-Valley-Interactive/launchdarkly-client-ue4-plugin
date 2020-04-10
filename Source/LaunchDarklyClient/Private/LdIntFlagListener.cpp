#include "LdIntFlagListener.h"

#include "LaunchDarklyClient.h"

ULdIntFlagListener::ULdIntFlagListener()
{

}

void ULdIntFlagListener::BeginDestroy()
{
	Unregister();

	Super::BeginDestroy();
}

void ULdIntFlagListener::Unregister()
{
	if(!IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdIntFlagListener::UnregisterWithFlag() called for flag '%s' when not registered; call aborted."), *(this->FlagName));
		return;
	}

	OnIntFlagChangedDynamicDelegate.Clear();
	FLaunchDarklyClientModule::Get()->UnregisterIntFlagListener(this, FlagName);
}

void ULdIntFlagListener::RegisterWithFlag(FString FN, int DV)
{
	if(IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdIntFlagListener::RegisterWithFlag() called for flag '%s' when already registered with '%s'; call aborted."), *(this->FlagName), *FlagName);
		return;
	}

	this->FlagName = FN;
	this->DefaultVal = DV;
	this->IsRegistered = true;

	FLaunchDarklyClientModule::Get()->RegisterIntFlagListener(this, FlagName);
}

void ULdIntFlagListener::ValueChanged()
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdIntFlagListener::ValueChanged() called for flag '%s'."), *(this->FlagName));
	OnIntFlagChangedDynamicDelegate.Broadcast(FLaunchDarklyClientModule::Get()->GetIntVariation(FlagName, DefaultVal));
}

void ULdIntFlagListener::ValueChanged(int FlagValue)
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdIntFlagListener::ValueChanged(...) called for flag '%s'."), *(this->FlagName));
	OnIntFlagChangedDynamicDelegate.Broadcast(FlagValue);
}