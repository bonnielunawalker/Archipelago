#ifndef AGENT_H
#define AGENT_H

#include "graphics.h"
#include "location.h"

class Agent {
private:
	arc::Color _color;
public:
	Location location;
	Agent(int x, int y, arc::Color color);

	// Render the agent to the screen.
	void Render();
};

#endif