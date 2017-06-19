#include <stdexcept>
#include <string>
#include <list>

#include "graphics.h"
namespace arc {
	void arc::Init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::string msg = "SDL was not initialised with the following error:\n";
			msg += SDL_GetError();
			throw std::runtime_error(msg);
		}

		events = std::list<arc::Event>();
	}

	void arc::CreateWindow(char* name, int sizeX, int sizeY) {
		// Create the window.
		SDL_Window *tempWindow;
		tempWindow = SDL_CreateWindow(name, 100, 100, sizeX, sizeY, SDL_WINDOW_OPENGL);

		if (tempWindow == NULL)
			throw std::exception("New SDL window could not be created.");

		// Create a renderer for the window.
		SDL_Renderer *tempRenderer;
		tempRenderer = SDL_CreateRenderer(tempWindow, -1, 0);

		if (tempRenderer == NULL)
			throw std::runtime_error("Renderer for the window could not be created");

		window = tempWindow;
		renderer = tempRenderer;
		bgColor = BLACK;
	}

	void arc::Point(int x, int y, Color color) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawPoint(renderer, x, y);
	}

	void arc::Rectangle(int x1, int y1, int x2, int y2, Color color) {
		SDL_Rect rect;
		rect.x = x1;
		rect.y = y1;
		rect.h = x2 - x1;
		rect.w = y2 - y1;

		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawRect(renderer, &rect);
	}

	void arc::SetBackgroundColor(Color color) {
		bgColor = color;
	}

	void arc::ClearScreen() {
		SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
		SDL_RenderClear(renderer);
	}

	void arc::Update() {
		// TODO: Events should be filtered into seperate lists here.
		// Events should not be iterated over like in KeyDown, but instead be indexed instead.
		SDL_FlushEvents(SDL_QUIT, SDL_LASTEVENT);
		events = std::list<Event>();

		Event event;
		while (SDL_PollEvent(&event)) {
			events.push_back(event);
		}
	}

	void arc::Render() {
		SDL_RenderPresent(renderer);
	}

	bool arc::KeyDown(char key) {
		if (!events.empty())
			for (std::list<Event>::const_iterator iterator = events.begin(); iterator != events.end(); ++iterator) {
				Event e = *iterator;
				if (e.type == SDL_KEYDOWN)
					if (e.key.keysym.sym == key)
						return true;
			}

		return false;
	}

	bool arc::WindowCloseRequested() {
		if (!events.empty())
			for (std::list<Event>::const_iterator iterator = events.begin(); iterator != events.end(); ++iterator) {
				Event e = *iterator;
				if (e.type == SDL_QUIT)
					return true;
			}

		return false;
	}

	void arc::Quit() {
		SDL_Quit();
	}
}