#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BarWidget.h"
#include "RPGHUD.generated.h"


UCLASS()
class CPP_UNREAL_1_API ARPGHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	// I had to leave this part as a comment because Visual Studio keeps giving me build errors
	// But it just won't say where and doesn't show me any errors prior to attempting to build
	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Progress Bar")
	void SetPercent(const float& percent);*/

private:
	UBarWidget* m_BarWidget;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UBarWidget> m_BarWidgetPrefab;
};