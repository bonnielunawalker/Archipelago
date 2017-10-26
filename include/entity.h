#ifndef AGENT_H
#define AGENT_H

#include "graphics.h"
#include "point2.h"
#include <list>

class Entity {
private:
	arc::Color _color;
	std::list<arc::Point2D<float>> _shape;
public:
	arc::Point2D<float> location;

	Entity(arc::Point2D<float> loc, arc::Color color);

    Entity(arc::Point2D<int> loc, arc::Color color);

    Entity(float x, float y, arc::Color color);

	// Render the agent to the screen.
	void Render();

	// Entity destructor. Removes color, shape and location.
	~Entity();
};

#endif