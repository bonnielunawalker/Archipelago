#ifndef TEXT_H
#define TEXT_H

#include "SDL.h"
#include "SDL_ttf.h"

namespace arc {
	class TextObject {
	private:
		SDL_Surface* _surface;
		SDL_Texture* _texture;
		SDL_Rect _rect;
	public:
		TextObject(const char* text, int x, int y, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);

		~TextObject();

		// Render the text to the screen.
		void Render(SDL_Renderer* renderer);
	};
}

#endif