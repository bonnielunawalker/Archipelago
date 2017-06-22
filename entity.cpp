#include "entity.h"

#include <iostream> // TODO: Remove this, for debug purposes only.

Entity::Entity(int x, int y, arc::Color color) {
	location = arc::Point2D(x, y);
	_color = color;

	_shape = {
		arc::Point2D( 0, -6),
		arc::Point2D(-6,  10),
		arc::Point2D( 6,  10)
	};
}

Entity::Entity(arc::Point2D loc, arc::Color color) {
	location = arc::Point2D();
	location.x = loc.x;
	location.y = loc.y;
	_color = color;
}

void Entity::Render() {
	arc::Polygon(_shape, location.x, location.y, _color);
}
