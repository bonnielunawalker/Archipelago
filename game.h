#ifndef GAME_H
#define GAME_H

#include <list>
#include "entity.h"

class Game {
private:
	std::list<Entity*> _entities;
public:
	Game();

	// Add an entity to the game world.
	void AddEntity(Entity *entity);

	// Render all game entities.
	void RenderEntities();
};

#endif