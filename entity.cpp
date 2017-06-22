#include "entity.h"

#include <iostream> // TODO: Remove this, for debug purposes only.

Entity::Entity(int x, int y, arc::Color color) {
	location = arc::Point2D();
	location.x = x;
	location.y = y;
	_color = color;
}

Entity::Entity(arc::Point2D loc, arc::Color color) {
	location = arc::Point2D();
	location.x = loc.x;
	location.y = loc.y;
	_color = color;
}

void Entity::Render() {
	arc::Circle(location.x, location.y, 100, _color);
}