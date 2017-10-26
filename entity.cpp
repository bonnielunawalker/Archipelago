#include "include/entity.h"

#include <iostream> // TODO: Remove this, for debug purposes only.

Entity::Entity(int x, int y, arc::Color color) {
	location = arc::Point2D(x, y);
	_color = color;

	_shape = {
		arc::Point2D(  0,  -12),
		arc::Point2D(-12,   20),
		arc::Point2D( 12,   20)
	};
}

Entity::Entity(arc::Point2D loc, arc::Color color) {
	location = arc::Point2D(loc.x, loc.y);
	_color = color;

	_shape = {
		arc::Point2D(0,  -12),
		arc::Point2D(-12,   20),
		arc::Point2D(12,   20)
	};
}

void Entity::Render() {
	arc::Polygon(_shape, location.x, location.y, _color);
}

Entity::~Entity() {
	delete &_color;
	delete[] &_shape;
	delete &location;
}