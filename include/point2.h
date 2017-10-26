#ifndef POINT2D
#define POINT2D

#include <iostream>

namespace arc {
    template <class T>
	class Point2D {
	public:
		T x;
		T y;

		Point2D();

		Point2D(T otherX, T otherY);

        Point2D(const Point2D<T>& otherPnt);
	};

    template <class T>
    Point2D<T>::Point2D() {
        x = 0;
        y = 0;
    }

    template <class T>
    Point2D<T>::Point2D(T otherX, T otherY) {
        x = otherX;
        y = otherY;
    }

    template <class T>
    Point2D<T>::Point2D(const Point2D<T>& otherPnt) {
        x = otherPnt.x;
        y = otherPnt.y;
    }

    template <class T>
    std::ostream& operator<<(std::ostream& os, const Point2D<T>& pnt) {
        os << pnt.x << ", " << pnt.y;
        return os;
    }
}

#endif