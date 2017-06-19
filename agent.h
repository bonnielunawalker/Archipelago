#ifndef AGENT_H
#define AGENT_H

#include "graphics.h"
#include "location.h"

class Agent {
private:
	Location _location;
	arc::Color _color;
public:
	Agent(int x, int y, arc::Color color);

	// Render the agent to the screen.
	void Render();
};

#endif