#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destructible.h"
#include "DestructibleCube.generated.h"

UCLASS()
class CPP_UNREAL_1_API ADestructibleCube : public AActor, public IDestructible
{
	GENERATED_BODY()
	
public:	
	ADestructibleCube();
	~ADestructibleCube();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void DestroyObject();

	void DestroyObject_Implementation() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destructible Cube", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_Mesh;
};