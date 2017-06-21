#include "graphics.h"
#include "game.h"
#include "entity.h"

#include <iostream>

int main(int argc, char *argv[]) {
	Game game = Game();
	Entity *e = new Entity(500, 500, arc::WHITE);
	game.AddEntity(e);
	arc::CreateWindow("Test", 1000, 1000);
	arc::SetBackgroundColor(arc::BLUE);

	bool set = false;

	while (!arc::WindowCloseRequested()) {
		arc::GetInput();

		if (arc::KeyDown('a'))
			e->location.x--;			
		if (arc::KeyDown('d'))
			e->location.x++;
		if (arc::KeyDown('w'))
			e->location.y--;
		if (arc::KeyDown('s'))
			e->location.y++;

		if (arc::MouseButtonDown(arc::MOUSE_LEFT))
			game.AddEntity(new Entity(arc::MousePosition(), arc::GREEN));

		arc::ClearScreen();
		game.RenderEntities();
		arc::Render();
	}
	
	arc::Quit();
	return 0;
}