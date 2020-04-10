#pragma once

#include "LdNodeObject.generated.h"

class FJsonObject;

UCLASS()
class LAUNCHDARKLYCLIENT_API ULdNodeObject : public UObject
{
	GENERATED_BODY()
public:
	ULdNodeObject();
	void Initialize(TSharedPtr<FJsonObject> LdData);
	TSharedPtr<FJsonObject> GetObjectData();

private:
	TSharedPtr<FJsonObject> LdNodeData = nullptr;	
	bool Initialized = false;
};