/**
 * Archipelago
 * game.h
 *
 * Class that acts as container for game entities.
 *
 * @author Bryn Walker
 */

#include "include/game.h"

#include <iostream> // TODO: Remove this, for debugging purposes only.
#include <sstream>

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

	std::stringstream stream;
	stream << "Number of entities: " << _entities.size();

	arc::Text(stream.str(), 2, 11, arc::FONT_MONO, arc::GREEN);

	// TODO: Profile this. A faster way of iterating through all entities probably exists.
}