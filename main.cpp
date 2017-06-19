#include <iostream>
#include "graphics.h"
#include "SDL.h"

int main(int argc, char *argv[]) {
	Graphics gfx = Graphics();

	bool loop = true;

	gfx.CreateWindow("Test", 1000, 1000);
	gfx.SetBackgroundColor(gfx.BLUE);

	while (loop) {
		gfx.Update();
		gfx.Render();

		if (gfx.KeyDown('a'))
			gfx.SetBackgroundColor(gfx.RED);
		else if (gfx.KeyDown('s'))
			gfx.SetBackgroundColor(gfx.BLUE);
	}
	
	gfx.Quit();
	return 0;
}