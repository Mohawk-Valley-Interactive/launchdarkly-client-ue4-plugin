#include "LdFloatFlagListener.h"

#include "LaunchDarklyClient.h"

ULdFloatFlagListener::ULdFloatFlagListener()
{

}

void ULdFloatFlagListener::BeginDestroy()
{
	Unregister();

	Super::BeginDestroy();
}

void ULdFloatFlagListener::Unregister()
{
	if(!IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdFloatFlagListener::UnregisterWithFlag() called for flag '%s' when not registered; call aborted."), *(this->FlagName));
		return;
	}

	OnFloatFlagChangedDynamicDelegate.Clear();
	FLaunchDarklyClientModule::Get()->UnregisterFloatFlagListener(this, FlagName);
}

void ULdFloatFlagListener::RegisterWithFlag(FString FN, float DV)
{
	if(IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdFloatFlagListener::RegisterWithFlag() called for flag '%s' when already registered with '%s'; call aborted."), *(this->FlagName), *FlagName);
		return;
	}

	this->FlagName = FN;
	this->DefaultVal = DV;
	this->IsRegistered = true;

	FLaunchDarklyClientModule::Get()->RegisterFloatFlagListener(this, FlagName);
}

void ULdFloatFlagListener::ValueChanged()
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdFloatFlagListener::ValueChanged() called for flag '%s'."), *(this->FlagName));
	OnFloatFlagChangedDynamicDelegate.Broadcast(FLaunchDarklyClientModule::Get()->GetFloatVariation(FlagName, DefaultVal));
}

void ULdFloatFlagListener::ValueChanged(float FlagValue)
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdFloatFlagListener::ValueChanged(...) called for flag '%s'."), *(this->FlagName));
	OnFloatFlagChangedDynamicDelegate.Broadcast(FlagValue);
}