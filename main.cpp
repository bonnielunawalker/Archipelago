#include <iostream>
#include "graphics.h"

int main(int argc, char *argv[]) {
	arc::CreateWindow("Test", 1000, 1000);
	arc::SetBackgroundColor(arc::BLUE);

	while (!arc::WindowCloseRequested()) {
		arc::Update();
		arc::ClearScreen();
		arc::Render();

		if (arc::KeyDown('a'))
			arc::SetBackgroundColor(arc::RED);
		else if (arc::KeyDown('s'))
			arc::SetBackgroundColor(arc::BLUE);
	}
	
	arc::Quit();
	return 0;
}