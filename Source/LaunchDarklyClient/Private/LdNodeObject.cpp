#include "LdNodeObject.h"
#include "Dom/JsonObject.h"

ULdNodeObject::ULdNodeObject()
{
	LdNodeData = nullptr;
}

void ULdNodeObject::Initialize(TSharedPtr<FJsonObject> const LdData)
{
	LdNodeData = LdData;
}

TSharedPtr<FJsonObject> ULdNodeObject::GetObjectData()
{
	return LdNodeData;
}
