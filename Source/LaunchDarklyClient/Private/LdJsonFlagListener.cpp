#include "LdJsonFlagListener.h"

#include "LaunchDarklyClient.h"
#include "LdNodeObject.h"

ULdJsonFlagListener::ULdJsonFlagListener()
{

}

void ULdJsonFlagListener::BeginDestroy()
{
	Unregister();

	Super::BeginDestroy();
}

void ULdJsonFlagListener::Unregister()
{
	if(!IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdJsonFlagListener::UnregisterWithFlag() called for flag '%s' when not registered; call aborted."), *(this->FlagName));
		return;
	}

	OnJsonFlagChangedDynamicDelegate.Clear();
	FLaunchDarklyClientModule::Get()->UnregisterJsonFlagListener(this, FlagName);
}

void ULdJsonFlagListener::RegisterWithFlag(FString FN, ULdNodeObject* DV)
{
	if(IsRegistered)
	{
		UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdJsonFlagListener::RegisterWithFlag() called for flag '%s' when already registered with '%s'; call aborted."), *(this->FlagName), *FlagName);
		return;
	}

	this->FlagName = FN;
	this->DefaultVal = DV;
	this->IsRegistered = true;

	FLaunchDarklyClientModule::Get()->RegisterJsonFlagListener(this, FlagName);
}

void ULdJsonFlagListener::ValueChanged()
{
	TSharedPtr<FJsonObject> JsonDefault = DefaultVal != NULL ? DefaultVal->GetObjectData() : NULL;
	TSharedPtr<FJsonObject> JsonData = FLaunchDarklyClientModule::Get()->GetJsonVariation(FlagName, JsonDefault);

	ULdNodeObject* FlagValue = NewObject<ULdNodeObject>();
	FlagValue->Initialize(JsonData);
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdJsonFlagListener::ValueChanged() called for flag '%s'."), *(this->FlagName));
	OnJsonFlagChangedDynamicDelegate.Broadcast(FlagValue);
}

void ULdJsonFlagListener::ValueChanged(ULdNodeObject* FlagValue)
{
	UE_LOG(LaunchDarklyClient, Warning, TEXT("ULdJsonFlagListener::ValueChanged(...) called for flag '%s'."), *(this->FlagName));
	OnJsonFlagChangedDynamicDelegate.Broadcast(FlagValue);
}