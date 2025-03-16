#include "BarWidget.h"

void UBarWidget::NativeConstruct(UProgressBar* progressBar)
{
	m_ProgressBar = progressBar;
}

// I had to leave this part as a comment because Visual Studio keeps giving me build errors
// But it just won't say where and doesn't show me any errors prior to attempting to build
/*void UBarWidget::SetPercent(const float& percent)
{
	// I looked up in the Unreal API Documentation how to use progress bars
	if (m_ProgressBar != nullptr)
	{
		float clampedPercent = FMath::Clamp(percent, 0.0f, 1.0f);
		m_ProgressBar->SetPercent(clampedPercent);

		if (m_Gradient != nullptr)
		{
			FLinearColor barColor = m_Gradient->GetLinearColorValue(clampedPercent);
			m_ProgressBar->SetFillColorAndOpacity(barColor);
		}
	}
}*/