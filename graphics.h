#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <list>

#include "SDL.h"
#include "window.h"

namespace arc {
	typedef SDL_Event Event;

	typedef SDL_Color Color;

	// Namespace level members
	static SDL_Renderer *renderer;
	static SDL_Window *window;
	static Color bgColor;
	static std::list<Event> events;

	// Colors
	const Color WHITE = { 255, 255, 255, 255 };
	const Color BLACK = { 0, 0, 0, 255 };
	const Color RED = { 255, 0, 0, 255 };
	const Color GREEN = { 0, 255, 0, 255 };
	const Color BLUE = { 0, 0, 255, 255 };

	// Initialise SDL and make sure everything's working.
	void Init();

	// Create a new SDL window to render to.
	void CreateWindow(char* name, int sizeX, int sizeY);

	// Draws a single pixel to the screen at the given x and y coordinates.
	void Point(int x, int y, Color color);

	// Draws a rectangle to the screen with the given top left and bottom right coordinates.
	void Rectangle(int x1, int y1, int x2, int y2, Color color);

	// Set background color for the window.
	void SetBackgroundColor(Color color);

	// Clear the screen ready for rendering.
	void ClearScreen();

	// Handle events since last call to update. Clears all old events.
	void Update();

	// Render all data.
	void Render();

	// Returns whether the given key was down at the last call to Update().
	bool KeyDown(char key);

	// Returns whether the user requested the window be closed.
	bool WindowCloseRequested();

	// Shut down the window and quit the application.
	void Quit();
}

#endif