#ifndef AGENT_H
#define AGENT_H

#include "graphics.h"
#include "point2.h"
#include <list>

class Entity {
private:
	arc::Color _color;
	std::list<arc::Point2D> _shape;
public:
	arc::Point2D location;

	Entity(int x, int y, arc::Color color);

	// Overloaded constructor that takes a Point2D to initialise the agent's location.
	Entity(arc::Point2D loc, arc::Color color);

	// Render the agent to the screen.
	void Render();

	// Entity destructor. Removes color, shape and location.
	~Entity();
};

#endif