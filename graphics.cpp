#include <stdexcept>
#include <string>
#include <list>
#include <sstream>
#include <string>

#include <iostream> // TODO: Remove this, for debugging purposes only.

#include "graphics.h"

namespace arc {
	// Forward declaration of extern members.
	Font* FONT_MONO;

	void Init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::string msg = "SDL could not be initialised due to the following error:\n";
			msg += SDL_GetError();
			std::cerr << msg << std::endl;
			exit(-1);
		}

		if (TTF_Init() < 0) {
			std::string msg = "TTF could not be initialised due to the following error:\n";
			msg += TTF_GetError();
			std::cerr << msg << std::endl;
			exit(-1);
		}

		FONT_MONO = TTF_OpenFont("C:\\mono.ttf", 11); // TODO: Change file path, this is just for debugging font loading.

		std::cout << "Finished intialization\nApplication running in " << SDL_GetBasePath() << std::endl;
	}

	void CreateWindow(char* name, int sizeX, int sizeY) {
		// Create the window.
		SDL_Window *tempWindow;
		tempWindow = SDL_CreateWindow(name, 100, 100, sizeX, sizeY, SDL_WINDOW_OPENGL);

		if (tempWindow == NULL)
			std::cerr << "New SDL window could not be created." << std::endl;

		// Create a renderer for the window.
		SDL_Renderer *tempRenderer;
		tempRenderer = SDL_CreateRenderer(tempWindow, -1, 0);

		if (tempRenderer == NULL)
			std::cerr << "Renderer for the window could not be created" << std::endl;

		window = tempWindow;
		renderer = tempRenderer;
		bgColor = BLACK;
	}

	int GetFramerate() {
		int frametimesIndex;
		int getTicks;
		
		// Get the frame we need to add next.
		frametimesIndex = frameCount % FRAME_VALUES;

		getTicks = SDL_GetTicks();

		// Save frame data.
		frametimes[frametimesIndex] = getTicks - frametimeLast;
		frametimeLast = getTicks;

		// Increment the number of frames measured since the start of the application.
		frameCount++;
		int count;

		if (frameCount < FRAME_VALUES)
			count = frameCount;
		else
			count = FRAME_VALUES;

		// Do the actual maths to find out the average fps over FRAME_VALUES number of frames.
		float framesPerSecond = 0;
		for (int i = 0; i < count; i++)
			framesPerSecond += frametimes[i];

		framesPerSecond /= count;

		// Format the result.
		framesPerSecond = 1000.f / framesPerSecond;

		return (int)framesPerSecond;
	}

	void ShowFPS() {
		int fps = GetFramerate();
		std::stringstream stream;
		stream << "FPS: " << fps;
		Text(stream.str(), 2, 2, FONT_MONO, GREEN);
	}

	void Point(int x, int y, Color color) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawPoint(renderer, x, y);
	}

	void Rectangle(int x1, int y1, int x2, int y2, Color color) {
		SDL_Rect rect;
		rect.x = x1;
		rect.y = y1;
		rect.h = x2 - x1;
		rect.w = y2 - y1;

		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawRect(renderer, &rect);
	}

	void Circle(int x1, int y1, int radius, Color color) {
		// Draw a circle using Bresenham's circle drawing method.
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		int x2 = 0;
		int y2 = radius;
		int p = 3 - (2 * radius);

		while (x2 <= y2)
		{
			SDL_RenderDrawPoint(renderer, x1 + x2, y1 + y2);
			SDL_RenderDrawPoint(renderer, x1 - x2, y1 + y2);
			SDL_RenderDrawPoint(renderer, x1 + x2, y1 - y2);
			SDL_RenderDrawPoint(renderer, x1 - x2, y1 - y2);
			SDL_RenderDrawPoint(renderer, x1 + y2, y1 + x2);
			SDL_RenderDrawPoint(renderer, x1 + y2, y1 - x2);
			SDL_RenderDrawPoint(renderer, x1 - y2, y1 + x2);
			SDL_RenderDrawPoint(renderer, x1 - y2, y1 - x2);

			x2 = x2 + 1;

			if (p<0)
				p = p + 4 * (x2)+6;
			else
			{
				p = p + 4 * (x2 - y2) + 10;
				y2 = y2 - 1;
			}
		}
	}

	void Text(char* text, int x, int y, Font* font, Color color) {
		std::string s = std::string(text);

		// Make sure the string can actually be rendered.
		// Exception is not needed since a string with no content would be rendered as blank anyway.
		if (s.length() == 0) {
			std::cerr << "Text fields of length 0 cannot be rendered." << std::endl;
			return;
		}

		TextObject* newText = new TextObject(s.c_str(), x, y, arc::FONT_MONO, color, renderer);
		textObjects.push_back(newText);
	}

	void Text(int text, int x, int y, Font* font, Color color) {
		std::string s = std::to_string(text);

		if (s.length() == 0) {
			std::cerr << "Text fields of length 0 cannot be rendered." << std::endl;
			return;
		}

		TextObject* newText = new TextObject(s.c_str(), x, y, arc::FONT_MONO, color, renderer);
		textObjects.push_back(newText);
	}

	void Text(std::string text, int x, int y, Font* font, Color color) {
		if (text.length() == 0) {
			std::cerr << "Text fields of length 0 cannot be rendered." << std::endl;
			return;
		}

		TextObject* newText = new TextObject(text.c_str(), x, y, arc::FONT_MONO, color, renderer);
		textObjects.push_back(newText);
	}

	void SetBackgroundColor(Color color) {
		bgColor = color;
	}

	void ClearScreen() {
		SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
		SDL_RenderClear(renderer);
	}

	void GetInput() {
		Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_KEYDOWN :
				keyboardEvents[e.key.keysym.sym] = true; // TODO: Currently throws an exception if a mod key is pressed.
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

	void Render() {
		if (!textObjects.empty()) {
			for (TextObject* t : textObjects) {
				t->Render(renderer);
				delete t;
			}
			textObjects.clear();
		}

		SDL_RenderPresent(renderer);
	}

	bool KeyDown(char key) {
		return keyboardEvents[key];
	}

	bool MouseButtonDown(char button) {
		return mouseDownEvents[button];
	}

	bool WindowCloseRequested() {
		return quitRequested;
	}

	Point2D MousePosition() {
		Point2D pnt = Point2D();
		SDL_GetMouseState(&pnt.x, &pnt.y);
		return pnt;
	}

	void Quit() {
		TTF_Quit();
		SDL_Quit();
	}
}