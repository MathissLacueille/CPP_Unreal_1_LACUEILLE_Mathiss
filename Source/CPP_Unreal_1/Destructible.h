#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Destructible.generated.h"

UINTERFACE(MinimalAPI)
class UDestructible : public UInterface
{
	GENERATED_BODY()
};

class CPP_UNREAL_1_API IDestructible
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void DestroyObject();
};