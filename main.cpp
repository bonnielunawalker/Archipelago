#include "graphics.h"
#include "game.h"
#include "entity.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	// Initialise archipelago and open a window.
	arc::Init();
	arc::CreateWindow("arc application", 1000, 1000);
	arc::SetBackgroundColor(arc::BLACK);

	Game game = Game();
	Entity* e = new Entity(500, 500, arc::WHITE);
	game.AddEntity(e);
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
		if (arc::MouseButtonDown(arc::MOUSE_RIGHT))
			game.AddEntity(new Entity(arc::MousePosition(), arc::RED));
		if (arc::MouseButtonDown(arc::MOUSE_MIDDLE))
			game.AddEntity(new Entity(arc::MousePosition(), arc::BLUE));

		arc::ClearScreen();
		arc::ShowFPS();
		game.RenderEntities();
		
		arc::Render();
	}
	
	arc::Quit();
	return 0;
}