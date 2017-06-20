#include <iostream>
#include "graphics.h"
#include "game.h"
#include "agent.h"

int main(int argc, char *argv[]) {
	Game game = Game();
	Agent a = Agent(500, 500, arc::WHITE);
	game.AddAgent(&a);
	arc::CreateWindow("Test", 1000, 1000);
	arc::SetBackgroundColor(arc::BLUE);

	while (!arc::WindowCloseRequested()) {
		arc::Update();

		if (arc::KeyDown('a'))
			a.location.x--;			
		if (arc::KeyDown('d'))
			a.location.x++;
		if (arc::KeyDown('w'))
			a.location.y--;
		if (arc::KeyDown('s'))
			a.location.y++;

		arc::ClearScreen();
		game.RenderAgents();
		arc::Render();
	}
	
	arc::Quit();
	return 0;
}