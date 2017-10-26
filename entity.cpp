#include "include/entity.h"

Entity::Entity(arc::Point2D<float> loc, arc::Color color){
	location = arc::Point2D<float>(loc.x, loc.y);
	_color = color;

	_shape = {
        arc::Point2D<float>(  0,  -12),
        arc::Point2D<float>(-12,   20),
        arc::Point2D<float>( 12,   20)
	};
}

Entity::Entity(arc::Point2D<int> loc, arc::Color color) : Entity(arc::Point2D<float>(loc.x, loc.y), color) {}

Entity::Entity(float x, float y, arc::Color color) : Entity(arc::Point2D<float>(x, y), color) {}

void Entity::Render() {
	arc::Polygon(_shape, location.x, location.y, _color);
}

Entity::~Entity() {
	return; // TODO: This is currently a NOP. Fix this.
}