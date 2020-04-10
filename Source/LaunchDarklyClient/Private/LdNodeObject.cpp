#include "LdNodeObject.h"
#include "Dom/JsonObject.h"

ULdNodeObject::ULdNodeObject()
{
	LdNodeData = MakeShared<FJsonObject>();
}

void ULdNodeObject::Initialize(TSharedPtr<FJsonObject> const LdData)
{
	LdNodeData = LdData;
}

TSharedPtr<FJsonObject> ULdNodeObject::GetObjectData()
{
	return LdNodeData;
}
