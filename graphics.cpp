#include "graphics.h"
#include <stdexcept>
#include <string>

Graphics::Graphics() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::string msg = "SDL was not initialised with the following error:\n";
		msg += SDL_GetError();
		throw std::runtime_error(msg);
	}
}

void Graphics::CreateWindow(char* name, int sizeX, int sizeY) {
	// Create the window.
	SDL_Window *tempWindow;
	tempWindow = SDL_CreateWindow(name, 100, 100, sizeX, sizeY, SDL_WINDOW_OPENGL);

	if (tempWindow == NULL)
		throw std::exception("New SDL window could not be created.");
	else
		window = tempWindow;

	// Create a renderer for the window.
	SDL_Renderer *tempRenderer;
	tempRenderer = SDL_CreateRenderer(window, -1, 0);

	if (tempRenderer == NULL) {
		throw std::runtime_error("Renderer for the window could not be created");
		delete window;
		window = NULL; // Clean up the window.
	}
	else
		renderer = tempRenderer;
}

void Graphics::DestroyWindow() {
	// If the window doesn't exist, throw an exception.
	if (window == NULL)
		throw std::runtime_error("Window does not exist so cannot be destroyed.");
	else
		SDL_DestroyWindow(window);
}

void Graphics::SetBackgroundColor(Color color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Graphics::Update() {
	SDL_FlushEvents(SDL_QUIT, SDL_LASTEVENT);
	events = std::vector<Event>();

	Event event;
	while (SDL_PollEvent(&event)) {
		events.push_back(event);
	}
}

void Graphics::Render() {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

bool Graphics::KeyDown(char key) {
	if (!events.empty()) {
		for (int i = 0; i < events.size(); i++) {
			if (events[i].type == SDL_KEYDOWN) {
				if (events[i].key.keysym.sym == key)
					return true;
			}			
		}
	}
	
	return false;
}

void Graphics::Quit() {
	DestroyWindow();
	SDL_Quit();
}