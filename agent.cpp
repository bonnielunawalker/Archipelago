#include "agent.h"
#include <iostream>

Agent::Agent(int x, int y, arc::Color color) {
	_location.x, _location.y = x, y;
	_color = color;
}

void Agent::Render() {
	arc::Rectangle(_location.x, _location.y, _location.x + 100, _location.y + 100, _color);
}