/**
 * Archipelago
 * colors.h
 *
 * Contains definitions for several basic colors for use in Archipelago applications.
 *
 * @author Bryn Walker
 */

#pragma once

namespace arc {
	typedef SDL_Color Color;

	// Color definitions.
	const Color WHITE = { 255, 255, 255, 255 };
	const Color BLACK = { 0, 0, 0, 255 };
	const Color RED = { 255, 0, 0, 255 };
	const Color GREEN = { 0, 255, 0, 255 };
	const Color BLUE = { 0, 0, 255, 255 };

	const Color PURPLE = { 153, 0, 153, 255 };

	// TODO: Add more...
}