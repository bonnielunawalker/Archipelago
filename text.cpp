#include "text.h"
#include <iostream>
#include "graphics.h"

namespace arc {
	TextObject::TextObject(char* text, int x, int y, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer) {
		if (!(text == "")) {
			_surface = TTF_RenderText_Solid(font, text, color);

			// TODO: Need a better way to work with textures. Consider arc::Texture class?
			_texture = SDL_CreateTextureFromSurface(renderer, _surface);

			_rect.x = x;
			_rect.y = y;
			_rect.h = _surface->h;
			_rect.w = _surface->w;

			// TODO: Look at SDL FontCache library to improve performance.
		}		
	}

	void TextObject::Render(SDL_Renderer* renderer) {
		SDL_RenderCopy(renderer, _texture, NULL, &_rect);
	}
}
