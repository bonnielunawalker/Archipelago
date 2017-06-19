#include "agent.h"

Agent::Agent(int x, int y, arc::Color color) {
	_location = Location();
	_location.x = x;
	_location.y = y;
	_color = color;
}

void Agent::Render() {
	arc::Rectangle(_location.x, _location.y, _location.x + 100, _location.y + 100, _color);
}