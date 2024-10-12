#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int width = 120;
	int height = 30;
	float aspect = (float)width / height;
	float pixelAspect = 11.0f / 24.0f;

	float outerRadius = 0.7f;
	float innerRadius = 0.3f;

	char* screen = new char[width * height + 1];
	screen[width * height] = '\0';
	
	for (int t = 0; t < 10000000; t++)
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				float x = (float)i / width * 2.0f - 1.0f;
				float y = (float)j / height * 2.0f - 1.0f;
				x *= aspect * pixelAspect;
				x += sin(t * 0.001);
				float distance = x * x + y * y;
				char pixel = ' ';
				if (distance < outerRadius * outerRadius && distance > innerRadius * innerRadius)
				{
					pixel = '@';
				}
				screen[i + j * width] = pixel;
			}
		}
		cout << screen;
	}
	 
	delete[] screen;

	return 0;
}