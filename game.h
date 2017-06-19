#ifndef GAME_H
#define GAME_H

#include <list>
#include "agent.h"

class Game {
private:
	std::list<Agent> _agents;
public:
	Game();

	// Add an agent to the game world.
	void AddAgent(Agent agent);

	// Render all game agents.
	void RenderAgents();
};

#endif