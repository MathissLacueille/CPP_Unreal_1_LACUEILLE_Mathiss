#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.generated.h"

UCLASS()
class CPP_UNREAL_1_API AMovingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingCube();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving Cube", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oscillation", meta = (AllowPrivateAccess = "true"))
	float m_OscillationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oscillation", meta = (AllowPrivateAccess = "true"))
	float m_OscillationRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circle", meta = (AllowPrivateAccess = "true"))
	float m_CircleRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Circle", meta = (AllowPrivateAccess = "true"))
	float m_RunningTime;
};