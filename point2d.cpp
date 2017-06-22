#include "point2d.h"

namespace arc {
	Point2D::Point2D() {
		x = 0;
		y = 0;
	}

	Point2D::Point2D(int otherX, int otherY) {
		x = otherX;
		y = otherY;
	}

	std::ostream& operator<<(std::ostream& os, const Point2D pnt) {
		os << pnt.x << ", " << pnt.y;
		return os;
	}
}