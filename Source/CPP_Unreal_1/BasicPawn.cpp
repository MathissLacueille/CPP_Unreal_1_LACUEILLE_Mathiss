#include "BasicPawn.h"

ABasicPawn::ABasicPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_Mesh->SetupAttachment(RootComponent);

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_Camera->SetupAttachment(RootComponent);

	m_CameraOffset = FVector::ZeroVector;
	m_CameraRotation = FRotator::ZeroRotator;
	m_Camera->SetRelativeLocation(m_CameraOffset);
	m_Camera->SetRelativeRotation(m_CameraRotation);

	m_Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));
	m_Pivot->SetupAttachment(RootComponent);

	m_MoveSpeed = 94;
	m_RotationSpeed = 88;

	MovementMappingContext = nullptr;
	MoveAction = nullptr;

	m_MovementInput = FVector::ZeroVector;
	m_RotationInput = FVector::ZeroVector;
	m_InertialInput = FVector::ZeroVector;
}

void ABasicPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ABasicPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePawn(DeltaTime);
	RotatePawn(DeltaTime);
}

void ABasicPawn::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	SetMappingContext(true);
}

void ABasicPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABasicPawn::GetMovementInput);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ABasicPawn::StopMovementInput);

		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &ABasicPawn::GetRotationInput);
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Completed, this, &ABasicPawn::StopRotationInput);
	}
}

void ABasicPawn::SetMappingContext(bool value)
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (value)
				Subsystem->AddMappingContext(MovementMappingContext, 0);
			else
				Subsystem->RemoveMappingContext(MovementMappingContext);
		}
	}
}

void ABasicPawn::GetMovementInput(const FInputActionValue& Value)
{
	m_MovementInput = Value.Get<FVector>();
}

void ABasicPawn::StopMovementInput(const FInputActionValue& Value)
{
	m_MovementInput = FVector::ZeroVector;
}

void ABasicPawn::GetRotationInput(const FInputActionValue& Value)
{
	m_RotationInput = Value.Get<FVector>();
}

void ABasicPawn::StopRotationInput(const FInputActionValue& Value)
{
	m_RotationInput = FVector::ZeroVector;
}

void ABasicPawn::MovePawn(const float& deltaTime)
{
	m_InertialInput = FMath::VInterpConstantTo(m_InertialInput, m_RotationInput, deltaTime, m_RotationSpeed);

	if (m_InertialInput != FVector::ZeroVector)
	{
		FVector pawnLocation = m_Pivot->GetComponentLocation();

		FVector movementToAdd = FVector(FVector(-m_InertialInput.Y, 0.0f, 0.0f).X, -m_InertialInput.X, -FVector(-m_InertialInput.Y, 0.0f, 0.0f).Y);
		m_Pivot->AddWorldOffset(movementToAdd);
	}
}

void ABasicPawn::RotatePawn(const float& deltaTime)
{
	m_InertialInput = FMath::VInterpConstantTo(m_InertialInput, m_RotationInput, deltaTime, m_RotationSpeed);

	if (m_InertialInput != FVector::ZeroVector)
	{
		FRotator pawnRotation = m_Pivot->GetComponentRotation();
		pawnRotation.Pitch = 0.0f;
		pawnRotation.Roll = 0.0f;

		FVector relativeInput = pawnRotation.RotateVector(FVector(-m_InertialInput.Y, 0.0f, 0.0f));

		FRotator rotationToAdd = FRotator(relativeInput.X, -m_InertialInput.X, -relativeInput.Y);
		m_Pivot->AddWorldRotation(rotationToAdd);
	}
}