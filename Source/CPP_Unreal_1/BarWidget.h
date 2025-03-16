#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/ProgressBar.h>
#include "Curves/CurveLinearColor.h"
#include "BarWidget.generated.h"


UCLASS()
class CPP_UNREAL_1_API UBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct(UProgressBar* progressBar);

	// I had to leave this part as a comment because Visual Studio keeps giving me build errors
	// But it just won't say where and doesn't show me any errors prior to attempting to build
	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Progress Bar")
	void SetPercent(const float& percent);*/

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Progress Bar", meta = (AllowPrivateAccess = "true"))
	UProgressBar* m_ProgressBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gradient", meta = (AllowPrivateAccess = "true"))
	UCurveLinearColor* m_Gradient;
};