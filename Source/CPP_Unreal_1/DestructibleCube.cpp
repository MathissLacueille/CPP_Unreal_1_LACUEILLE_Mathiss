#include "DestructibleCube.h"

ADestructibleCube::ADestructibleCube()
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
}

ADestructibleCube::~ADestructibleCube()
{
}

void ADestructibleCube::BeginPlay()
{
	Super::BeginPlay();
}

void ADestructibleCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADestructibleCube::DestroyObject_Implementation()
{
	// I initially wanted to call this class's destructor
	// ~ADestructibleCube();
	// But VisualStudio kept telling me there was an error with the line above
	// More specifically, with the ~
	// So I looked up another way to destroy the object
	// I found this solution on Stack Overflow
	// Plenty of people were saying to use this method rather than call the destructor
	delete this;
}