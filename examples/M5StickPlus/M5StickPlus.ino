/***************************************************
Copyright (c) 2021 Luis Llamas
(www.luisllamas.es)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.  If not, see <http://www.gnu.org/licenses
****************************************************/

#include <M5StickCPlus.h>

#include <FpsCounter.hpp>

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
