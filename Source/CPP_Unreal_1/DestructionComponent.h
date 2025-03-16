#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "Destructible.h"
#include "DestructionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_UNREAL_1_API UDestructionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDestructionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void DestructionBeam();
	void DestructionDetection();

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destruction Component", meta = (AllowPrivateAccess = "true"))
	float m_Range;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destruction Component", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* m_Camera;

	AActor* m_Destructible;
};