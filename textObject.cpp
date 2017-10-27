/**
 * Archipelago
 * textObject.h
 *
 * Contains text information to be rendered to an Archipelago window.
 *
 * @author Bryn Walker
 */

#include "include/textObject.h"
#include <iostream>
#include "include/graphics.h"
#include <stdexcept>

namespace arc {
	TextObject::TextObject(const char* text, int x, int y, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer) {
		if (!(_surface = TTF_RenderText_Solid(font, text, color)))
			throw std::runtime_error("Could not create new text object: " + std::string(TTF_GetError()));

		// TODO: Need a better way to work with textures. Consider arc::Texture class?
		_texture = SDL_CreateTextureFromSurface(renderer, _surface);

		_rect.x = x;
		_rect.y = y;
		_rect.h = _surface->h;
		_rect.w = _surface->w;

		// TODO: Look at SDL FontCache library to improve performance.
	}

	TextObject::~TextObject() {
		SDL_FreeSurface(_surface);
		SDL_DestroyTexture(_texture);

		//delete &_surface; // TODO: Find a way to delete these properly
		//delete &_texture;
		//delete &_rect;
	}

	void TextObject::Render(SDL_Renderer* renderer) {
		SDL_RenderCopy(renderer, _texture, NULL, &_rect);
	}
}
