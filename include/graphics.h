/**
 * Archipelago
 * graphics.h
 *
 * Contains all of Archipelago's basic rendering methods as well as auxiliary tools for measuring performance.
 *
 * @author Bryn Walker
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <list>

#include "SDL.h"
#include "SDL_ttf.h"
#include "colors.h"
#include "point2.h"
#include "textObject.h"
#include "vector2.h"

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

	/**
 	* Initialises SDL and Archipelago and ensures everything is set up correctly.
 	*/
	void Init();

	/**
 	* Creates a new window to display graphics in.
 	*
 	* @param name The name of the windows to be displayed on the toolbar.
 	* @param sizeX The width of the window in pixels.
 	* @param sizeY The height of the window in pixels.
 	*/
	void CreateWindow(char* name, float sizeX, float sizeY);

	/**
 	* Calculates the current framerate of the application.
 	*
 	* @return Returns the current application framerate as an integer.
 	*/
	float GetFramerate();

	/**
	 * Renders the current framerate of the application to the window.
	 */
	void ShowFPS();

	/**
	 * Draws a single pixel to the screen at the given x and y coordinates.
	 *
	 * @param x The x position of the pixel to be drawn.
	 * @param y The y position of the pixel to be drawn.
	 * @param color The color the pixel should be drawn with.
	 */
	void Point(float x, float y, Color color);

	/**
	 * Draws a line between two x and y positions.
	 *
	 * @param x1 The x position of the first point.
	 * @param y1 The y position of the first point.
	 * @param x2 The x position of the second point.
	 * @param y2 The y position of the second point.
	 * @param color The color the line should be drawn with.
	 */
	void Line(float x1, float y1, float x2, float y2, Color color);

	/**
	 * Draws a rectangle to the screen with the given top left and bottom right coordinates.
	 *
	 * @param x1 The x position of the top left of the rectangle.
	 * @param y1 The y position of the top left of the rectangle.
	 * @param x2 The x position of the bottom right of the rectangle.
	 * @param y2 The y position of the bottom right of the rectangle.
	 * @param color The color the rectangle should be drawn with.
	 */
	void Rectangle(float x1, float y1, float x2, float y2, Color color);

	/**
	 * Draws a circle to the screen at the given central x and y coordinates with the given radius.
	 *
	 * @param x The x position of the centre of the circle.
	 * @param y The y position of the centre of the circle.
	 * @param r The radius of the circle.
	 * @param color The color the circle should be drawn with.
	 */
	void Circle(float x, float y, float r, Color color);

    /**
     * Draw a polygon of an arbitrary number of points from the list of points provided.
     * Points are considered relative to the x and y coordinates given.
     *
     * @param points The list of points to be drawn.
     * @param x The x position of the centre of the polygon.
     * @param y The y position of the centre of the polygon.
     * @param color The color the polygon should be drawn with.
     */
	void Polygon(std::list<Point2D<float>> points, float x, float y, Color color);

    /**
     * Draw the given string to the screen using the given font and color to the given x and y position.
     *
     * @param text The string to be drawn to the screen.
     * @param x The x position of the text.
     * @param y The y position of the text.
     * @param font The font the text will be rendered with.
     * @param color The color the string should be drawn with.
     */
	void Text(char* text, int x, int y, Font* font, Color color);

    /**
     * Draw the given string to the screen using the given font and color to the given x and y position.
     *
     * @param text The integer to be drawn to the screen.
     * @param x The x position of the text.
     * @param y The y position of the text.
     * @param font The font the text will be rendered with.
     * @param color The color the string should be drawn with.
     */
	void Text(float text, float x, float y, Font* font, Color color);

    /**
     * Draw the given string to the screen using the given font and color to the given x and y position.
     *
     * @param text The string to be drawn to the screen.
     * @param x The x position of the text.
     * @param y The y position of the text.
     * @param font The font the text will be rendered with.
     * @param color The color the string should be drawn with.
     */
	void Text(std::string text, float x, float y, Font* font, Color color);

    /**
     * Set the background color for the window.
     *
     * @param color The color the window's background color will be changed to.
     */
	void SetBackgroundColor(Color color);

    /**
     * Clear the screen ready for rendering.
     */
	void ClearScreen();

    /**
     * Handle all events since last call to arc::Update(). Clears all old events.
     */
	void GetInput();

    /**
     * Render all data to the screen.
     */
	void Render();

    /**
     * Returns whether the given key was down at the last call to arc::Update();
     *
     * @param key The key to be checked.
     * @return Returns true if the key was pressed. Otherwise returns false.
     */
	bool KeyDown(char key);

    /**
     * Returns whether the given mouse button was down at the last call to arc::Update().
     *
     * @param button The mouse button to be checked.
     * @return Returns true if the mouse button was pressed. Otherwise returns false.
     */
	bool MouseButtonDown(char button);

    /**
     * Returns an arc::Point2D with the x and y position of the mouse relative to the window.
     *
     * @return Returns a new arc::Point2D containing mouse position data.
     */
	Point2D<int> MousePosition();

    /**
     * Returns whether the user requested the window be closed.
     *
     * @return Returns true if a window close request has been made.
     */
	bool WindowCloseRequested();

    /**
     * Closes the current window and quits the application.
     */
	void Quit();
}

#endif