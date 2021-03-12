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
