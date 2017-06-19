#include "game.h"

Game::Game()
{
	_agents = std::list<Agent>();
}

void Game::AddAgent(Agent agent) {
	_agents.push_back(agent);
}

void Game::RenderAgents() {
	if (!_agents.empty())
		// Loop through all agents in the game...
		for (std::list<Agent>::const_iterator iterator = _agents.begin(); iterator != _agents.end(); ++iterator) {
			Agent a = *iterator;
			// ... and render them.
			a.Render();
		}
}