/***************************************************
Copyright (c) 2021 Luis Llamas
(www.luisllamas.es)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.  If not, see <http://www.gnu.org/licenses
****************************************************/

#pragma once

class FpsCounter
{
public:
	float Get()
	{
		return fps;
	}

	float Update(unsigned long millis)
	{
		counter ++;

		unsigned long elapsed = millis - lastUpdateTime;
		if (elapsed > refreshInterval)
		{
			fps = (float)counter * refreshInterval / elapsed;
			lastUpdateTime = millis;
			counter = 0;
		}
		return fps;
	}

private:
	unsigned long refreshInterval = 1000;

	unsigned long lastUpdateTime = 0;
	unsigned long prevTime = 0;
	unsigned long counter = 0;
	float fps = 0;
};
