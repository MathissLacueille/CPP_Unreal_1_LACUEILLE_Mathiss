#include "DestructionComponent.h"

UDestructionComponent::UDestructionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	m_Range = 85.0f;

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
}

void UDestructionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UDestructionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDestructionComponent::DestructionBeam()
{
}

void UDestructionComponent::DestructionDetection()
{
	FHitResult hit;

	ECollisionChannel channel(ECC_GameTraceChannel1);
	const FCollisionQueryParams traceParam(FName(TEXT("")), false, GetOwner());

	FVector startPosition = m_Camera->GetComponentLocation();
	FVector endPosition = startPosition + m_Camera->GetForwardVector() * m_Range;

	if (!GetWorld()->LineTraceSingleByChannel(OUT hit, startPosition, endPosition, channel, traceParam))
	{
		m_Destructible = nullptr;
		return;
	}

	AActor* hitActor = hit.GetActor();
	if (hitActor == nullptr)
	{
		m_Destructible = nullptr;
		return;
	}

	if (hitActor->GetClass()->ImplementsInterface(UDestructible::StaticClass()))
	{
		m_Destructible = hitActor;
		IDestructible::Execute_DestroyObject(m_Destructible);
	}
	else
	{
		m_Destructible = nullptr;
	}
}