#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"

#include "LaunchDarklyHelpers.generated.h"

class FJsonObject;
class ULdNodeObject;
class ULdUserObject;

UCLASS()
class LAUNCHDARKLYCLIENT_API ULaunchDarklyHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	////////////////////////////////////////////////////////////////////////////////////////////////
	// BLUEPRINT FACING ////////////////////////////////////////////////////////////////////////////
	UFUNCTION(BlueprintPure, Category="LaunchDarkly Helpers")
	static FVector LdNodeObjectToVector(ULdNodeObject* LdDataObject);

	UFUNCTION(BlueprintPure, Category="LaunchDarkly Helpers")
	static ULdNodeObject* VectorToLdNodeObject(FVector C);

	UFUNCTION(BlueprintPure, Category="LaunchDarkly Helpers")
	static FLinearColor LdNodeObjectToLinearColor(ULdNodeObject* LdDataObject);

	UFUNCTION(BlueprintPure, Category="LaunchDarkly Helpers")
	static ULdNodeObject* LinearColorToLdNodeObject(FLinearColor C);

	UFUNCTION(BlueprintPure, Category="LaunchDarkly Helpers")
	static FColor LdNodeObjectToColor(ULdNodeObject* LdDataObject);

	UFUNCTION(BlueprintPure, Category="LaunchDarkly Helpers")
	static ULdNodeObject* ColorToLdNodeObject(FColor C);

	UFUNCTION(BlueprintPure, Category="LaunchDarkly Helpers")
	static FString LdNodeObjectHashToString(ULdNodeObject* const LdNodeData);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// CODE FACING /////////////////////////////////////////////////////////////////////////////////
	static FString JsonObjectToString(TSharedPtr<FJsonObject> LdNodeData);

	static TSharedPtr<FJsonObject> StringToJsonObject(FString LdNodeData);
};