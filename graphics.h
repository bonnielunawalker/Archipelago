#pragma once

#include "SDL.h"
#include <vector>

class Graphics {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;	
	std::vector<SDL_Event> events;
public:
	typedef SDL_Event Event;

	typedef SDL_Color Color;
	const Color WHITE = { 255, 255, 255, 255 };
	const Color BLACK = { 0, 0, 0, 255 };
	const Color RED = { 255, 0, 0, 255 };
	const Color GREEN = { 0, 255, 0, 255 };
	const Color BLUE = { 0, 0, 255, 255 };

	// Default constructor. Initialises SDL and checks for errors.
	Graphics();

	// Create a new SDL window to render to.
	void CreateWindow(char* name, int sizeX, int sizeY);

	// Destroy the current SDL window.
	void DestroyWindow();

	// Set background color for the window.
	void SetBackgroundColor(Color color);

	// Handle events since last call to update. Clears all old events.
	void Update();

	// Clear the screen and render all data.
	void Render();

	// Returns whether the given key was down at the last call to Update().
	bool KeyDown(char key);

	// Shut down the window and quit the application.
	void Quit();
};