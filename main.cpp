#include <iostream>
#include "graphics.h"
#include "game.h"
#include "agent.h"

int main(int argc, char *argv[]) {
	Game game = Game();
	game.AddAgent(Agent(500, 500, arc::GREEN));
	arc::CreateWindow("Test", 1000, 1000);
	arc::SetBackgroundColor(arc::BLUE);

	while (!arc::WindowCloseRequested()) {
		arc::Update();
		arc::ClearScreen();
		game.RenderAgents();
		arc::Render();

		if (arc::KeyDown('a'))
			arc::SetBackgroundColor(arc::RED);
		else if (arc::KeyDown('s'))
			arc::SetBackgroundColor(arc::BLUE);
	}
	
	arc::Quit();
	return 0;
}