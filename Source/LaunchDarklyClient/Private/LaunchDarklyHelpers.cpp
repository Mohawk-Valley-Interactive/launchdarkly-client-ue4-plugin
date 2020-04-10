#include "LaunchDarklyHelpers.h"

#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "LdNodeObject.h"
#include "LdUserObject.h"

FVector ULaunchDarklyHelpers::LdNodeObjectToVector(ULdNodeObject* LdDataObject)
{
	TSharedPtr<FJsonObject> LdData = LdDataObject->GetObjectData();
	FVector V(
		LdData->HasTypedField<EJson::Number>("x") ? LdData->GetNumberField("x") : 0.0f,
		LdData->HasTypedField<EJson::Number>("y") ? LdData->GetNumberField("y") : 0.0f,
		LdData->HasTypedField<EJson::Number>("z") ? LdData->GetNumberField("z") : 0.0f
	);

	return V;
}

ULdNodeObject* ULaunchDarklyHelpers::VectorToLdNodeObject(FVector V)
{
	ULdNodeObject* NodeObject = NewObject<ULdNodeObject>();
	TSharedPtr<FJsonObject> Node = MakeShared<FJsonObject>();
	Node->SetNumberField("x", V.X);
	Node->SetNumberField("y", V.Y);
	Node->SetNumberField("z", V.Z);

	NodeObject->Initialize(Node);
	return NodeObject;
}

FColor ULaunchDarklyHelpers::LdNodeObjectToColor(ULdNodeObject* LdDataObject)
{
	TSharedPtr<FJsonObject> LdData = LdDataObject->GetObjectData();
	FColor C(
		LdData->HasTypedField<EJson::Number>("r") ? (uint8)LdData->GetNumberField("r") : 0,
		LdData->HasTypedField<EJson::Number>("g") ? (uint8)LdData->GetNumberField("g") : 0,
		LdData->HasTypedField<EJson::Number>("b") ? (uint8)LdData->GetNumberField("b") : 0,
		LdData->HasTypedField<EJson::Number>("a") ? (uint8)LdData->GetNumberField("a") : 0
	);

	return C;
}

ULdNodeObject* ULaunchDarklyHelpers::ColorToLdNodeObject(FColor C)
{
	ULdNodeObject* NodeObject = NewObject<ULdNodeObject>();
	TSharedPtr<FJsonObject> Node = MakeShared<FJsonObject>();

	Node->SetNumberField("a", C.A);
	Node->SetNumberField("r", C.R);
	Node->SetNumberField("g", C.G);
	Node->SetNumberField("b", C.B);

	NodeObject->Initialize(Node);
	return NodeObject;
}

FLinearColor ULaunchDarklyHelpers::LdNodeObjectToLinearColor(ULdNodeObject* LdDataObject)
{
	TSharedPtr<FJsonObject> LdData = LdDataObject->GetObjectData();
	FLinearColor C(
		LdData->HasTypedField<EJson::Number>("r") ? LdData->GetNumberField("r") : 0.0f,
		LdData->HasTypedField<EJson::Number>("g") ? LdData->GetNumberField("g") : 0.0f,
		LdData->HasTypedField<EJson::Number>("b") ? LdData->GetNumberField("b") : 0.0f,
		LdData->HasTypedField<EJson::Number>("a") ? LdData->GetNumberField("a") : 0.0f
	);

	return C;
}

ULdNodeObject* ULaunchDarklyHelpers::LinearColorToLdNodeObject(FLinearColor LC)
{
	ULdNodeObject* NodeObject = NewObject<ULdNodeObject>();
	TSharedPtr<FJsonObject> Node = MakeShared<FJsonObject>();

	Node->SetNumberField("a", LC.A);
	Node->SetNumberField("r", LC.R);
	Node->SetNumberField("g", LC.G);
	Node->SetNumberField("b", LC.B);

	NodeObject->Initialize(Node);
	return NodeObject;
}

FString ULaunchDarklyHelpers::LdNodeObjectHashToString(ULdNodeObject* const LdNodeData)
{
	return LdNodeData != nullptr ? JsonObjectToString(LdNodeData->GetObjectData()) : FString("NULL NODE");
}

FString ULaunchDarklyHelpers::JsonObjectToString(TSharedPtr<FJsonObject> LdNodeData)
{
	if(LdNodeData != nullptr)
	{
		FString JsonOutput;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&JsonOutput);
		FJsonSerializer::Serialize(LdNodeData.ToSharedRef(), Writer);

		return JsonOutput.IsEmpty() ? FString("{}") : JsonOutput;
	}

	return FString("{}");
}

TSharedPtr<FJsonObject> ULaunchDarklyHelpers::StringToJsonObject(FString LdNodeData)
{
	TSharedPtr<FJsonObject> JsonOutput = MakeShared<FJsonObject>(); 
	if(LdNodeData.IsEmpty() == false)
	{
		TSharedRef< TJsonReader<> > Writer = TJsonReaderFactory<>::Create(LdNodeData);
		FJsonSerializer::Deserialize(Writer, JsonOutput);
	}

	return JsonOutput;
}
