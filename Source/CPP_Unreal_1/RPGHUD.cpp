#include "RPGHUD.h"

void ARPGHUD::BeginPlay()
{
	m_BarWidget = Cast<UBarWidget>(CreateWidget(GetWorld(), m_BarWidgetPrefab));
	m_BarWidget->AddToViewport();
}

// I had to leave this part as a comment because Visual Studio keeps giving me build errors
// But it just won't say where and doesn't show me any errors prior to attempting to build
/*void UBarWidget::SetPercent(const float& percent)
{
	m_BarWidget->SetPercent(percent);
}*/