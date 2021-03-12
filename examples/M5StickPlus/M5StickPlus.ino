#include <M5StickCPlus.h>

#include "FpsCounter.hpp"

TFT_eSprite tftSprite = TFT_eSprite(&M5.Lcd);
FpsCounter fpsCounter;

void setup(void)
{
	Serial.begin(115200);
	M5.begin();

	tftSprite.setColorDepth(16);
	tftSprite.createSprite(m5.Lcd.width(), m5.Lcd.height());
	tftSprite.fillScreen(TFT_BLACK);
	tftSprite.setTextColor(TFT_WHITE);

}

void draw()
{
	tftSprite.fillScreen(TFT_BLUE);

	tftSprite.setCursor(10, 225);
	tftSprite.printf("Fps: %5.2f", fpsCounter.Get());

	tftSprite.pushSprite(0, 0);
}


void loop(void)
{
	fpsCounter.Update(millis());
	draw();
}
