
#pragma once

#include "Handles.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPBPLibrary.generated.h"

UCLASS()
class BPBP_API UBPBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, meta = (BlueprintAutocast), Category = "BPBP")
	static UBlueprintHandle* CastToBlueprint(UObject* Object)
	{
		UBlueprint* Blueprint = Cast<UBlueprint>(Object);
		return Blueprint ? FHandles::NewHandle<UBlueprintHandle>(Blueprint) : nullptr;
	}

	UFUNCTION(BlueprintPure, Category = "BPBP")
	static UBlueprintHandle* FindBlueprint(UBlueprint* BlueprintReference)
	{
		return BlueprintReference ? FHandles::NewHandle<UBlueprintHandle>(BlueprintReference) : nullptr;
	}

	UFUNCTION(BlueprintCallable, Category = "BPBP")
	static UEdGraphHandle* CreateFunction(UBlueprintHandle* Blueprint, const FName& Name);
};
