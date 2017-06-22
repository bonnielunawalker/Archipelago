#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <list>

#include "SDL.h"
#include "SDL_ttf.h"
#include "colors.h"
#include "point2d.h"
#include "textObject.h"

namespace arc {
	// Namespace level members.
	static SDL_Renderer* renderer;
	static SDL_Window* window;
	
	static Color bgColor;

	// Event storage.
	typedef SDL_Event Event;
	static bool keyboardEvents[128];
	static bool mouseDownEvents[5];
	static bool quitRequested;

	// Mouse button definitions.
	const int MOUSE_LEFT = 1;
	const int MOUSE_MIDDLE = 2;
	const int MOUSE_RIGHT = 3;

	// Framerate counter fields.
	const int FRAME_VALUES = 50;
	static int frametimes[FRAME_VALUES];
	static int frametimeLast = SDL_GetTicks();
	static int frameCount = 0;

	// Text rendering definitions.
	typedef TTF_Font Font;
	extern Font* FONT_MONO;
	static std::list<TextObject*> textObjects;

	// Initialise SDL and make sure everything's working.
	void Init();

	// Create a new SDL window to render to.
	void CreateWindow(char* name, int sizeX, int sizeY);

	// Returns the current application framerate.
	int GetFramerate();

	// Renders a framerate counter to the window.
	void ShowFPS();

	// Draws a single pixel to the screen at the given x and y coordinates.
	void Point(int x, int y, Color color);

	// Draws a rectangle to the screen with the given top left and bottom right coordinates.
	void Rectangle(int x1, int y1, int x2, int y2, Color color);

	// Draws a circle to the screen with at the given central x and y coordinates with the given radius.
	void Circle(int x1, int y1, int r, Color color);

	// Render the given string to the screen using the given font and color to the given x and y position.
	void Text(char* text, int x, int y, Font* font, Color color);
	void Text(int text, int x, int y, Font* font, Color color);
	void Text(std::string text, int x, int y, Font* font, Color color);

	// Set background color for the window.
	void SetBackgroundColor(Color color);

	// Clear the screen ready for rendering.
	void ClearScreen();

	// Handle events since last call to update. Clears all old events.
	void GetInput();

	// Render all data.
	void Render();

	// Returns whether the given key was down at the last call to Update().
	bool KeyDown(char key);

	// Returns whether the given mouse button was down at the last call to Update().
	bool MouseButtonDown(char button);

	// Returns a Point2D with the x and y position of the mouse relative to the window.
	Point2D MousePosition();

	// Returns whether the user requested the window be closed.
	bool WindowCloseRequested();

	// Shut down the window and quit the application.
	void Quit();
}

#endif