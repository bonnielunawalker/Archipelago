#include "window.h"

namespace arc {
	Window::Window(SDL_Window* window, SDL_Renderer* renderer) {
		_window = window;
		_renderer = renderer;
	}

	Window::~Window() {
		SDL_DestroyWindow(_window);
	}

	SDL_Renderer* Window::GetRenderer() {
		return _renderer;
	}
}