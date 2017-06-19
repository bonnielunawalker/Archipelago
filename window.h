#pragma once

#include "SDL.h"

namespace arc {
	class Window {
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
	public:
		Window();
		Window(SDL_Window* window, SDL_Renderer* renderer);
		~Window();

		// Allows access to the window's SDL renderer to be passed to SDL drawing methods.
		SDL_Renderer* GetRenderer();

	};
}