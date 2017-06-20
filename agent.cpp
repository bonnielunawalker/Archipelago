#include "agent.h"

#include <iostream> // TODO: Remove this, for debug purposes only.

Agent::Agent(int x, int y, arc::Color color) {
	location = Location();
	location.x = x;
	location.y = y;
	_color = color;
}

void Agent::Render() {
	arc::Rectangle(location.x, location.y, location.x + 100, location.y + 100, _color);
	std::cout << location.x << " " << location.y << std::endl;
}