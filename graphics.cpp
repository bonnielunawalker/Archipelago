#include <stdexcept>
#include <string>
#include <list>

#include <iostream> // TODO: Remove this, for debugging purposes only.

#include "graphics.h"

namespace arc {
	void arc::Init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::string msg = "SDL was not initialised with the following error:\n";
			msg += SDL_GetError();
			throw std::runtime_error(msg);
		}
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

	void arc::GetInput() {
		Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_KEYDOWN :
				keyboardEvents[e.key.keysym.sym] = true;
				break;
			case SDL_KEYUP :
				keyboardEvents[e.key.keysym.sym] = false;
				break;
			case SDL_MOUSEBUTTONDOWN :
				mouseDownEvents[e.button.button] = true;
				break;
			case SDL_MOUSEBUTTONUP :
				mouseDownEvents[e.button.button] = false;
				break;
			case SDL_QUIT :
				quitRequested = true;
			}
		}
	}

	void arc::Render() {
		SDL_RenderPresent(renderer);
	}

	bool arc::KeyDown(char key) {
		return keyboardEvents[key];
	}

	bool arc::MouseButtonDown(char button) {
		return mouseDownEvents[button];
	}

	bool arc::WindowCloseRequested() {
		return quitRequested;
	}

	Point2D arc::MousePosition() {
		Point2D pnt = Point2D();
		SDL_GetMouseState(&pnt.x, &pnt.y);
		return pnt;
	}

	void arc::Quit() {
		SDL_Quit();
	}
}