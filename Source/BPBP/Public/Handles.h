
#pragma once

#include "Handles.generated.h"

UCLASS(meta = (DisplayName = "Graph"))
class UEdGraphHandle : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UEdGraph* Delegate;
};

UCLASS()
class UBlueprintHandle : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UBlueprint* Delegate;
};

struct FHandles
{
	template<class HandleType, class DelegateType>
	static HandleType* NewHandle(DelegateType* Delegate)
	{
		HandleType* Handle = NewObject<HandleType>();
		Handle->Delegate = Delegate;
		return Handle;
	}
};
