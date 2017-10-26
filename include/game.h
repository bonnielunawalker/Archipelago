/**
 * Archipelago
 * game.h
 *
 * Class that acts as container for game entities.
 *
 * @author Bryn Walker
 */

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
	void AddEntity(Entity* entity);

	// Render all game entities.
	void RenderEntities();
};

#endif