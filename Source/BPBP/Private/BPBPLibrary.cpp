
#include "BPBPLibrary.h"
#include "BPBP.h"
#include "Kismet2/BlueprintEditorUtils.h"

UEdGraphHandle* UBPBPLibrary::CreateFunction(UBlueprintHandle* Blueprint, const FName& Name)
{
	UEdGraph* Graph = FBlueprintEditorUtils::CreateNewGraph(Blueprint->Delegate, Name, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
	FBlueprintEditorUtils::AddFunctionGraph<UClass>(Blueprint->Delegate, Graph, true, nullptr);
	return FHandles::NewHandle<UEdGraphHandle>(Graph);
}

