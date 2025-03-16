#include "MovingCube.h"

AMovingCube::AMovingCube()
{
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_Mesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		cubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (cubeVisualAsset.Succeeded())
	{
		m_Mesh->SetStaticMesh(cubeVisualAsset.Object);
		m_Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	m_OscillationSpeed = 0.0f;
	m_OscillationRange = 0.0f;
	m_CircleRadius = 0.0f;
}

void AMovingCube::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Same method as Matthieu used
	m_RunningTime += DeltaTime;
	FVector NewLocation = GetActorLocation();
	float DeltaHeightX = FMath::Sin(m_RunningTime * m_OscillationSpeed) * m_OscillationRange;
	float DeltaHeightY = FMath::Cos(m_RunningTime * m_OscillationSpeed) * m_OscillationRange;
	NewLocation.X += DeltaHeightX;
	NewLocation.Y += DeltaHeightY;
	SetActorLocation(NewLocation);
}