#include "game.h"

#include <iostream> // TODO: Remove this, for debugging purposes only.

Game::Game()
{
	_entities = std::list<Entity*>();
}

void Game::AddEntity(Entity* agent) {
	_entities.push_back(agent);
}

void Game::RenderEntities() {
	if (!_entities.empty())
		// Loop through all entities in the game...
		for (Entity* e : _entities) {
			// ... and render them.
			e->Render();
		}

	std::cout << "Number of entities: " << _entities.size() << std::endl;

	// TODO: Profile this. A faster way of iterating through all entities probably exists.
}