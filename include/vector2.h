/**
 * Archipelago
 * vector2.h
 *
 * Template class for containing positional offset data for game and graphical entities.
 * Contains a number of helper functions for performing operations with these entities.
 *
 * @author Bryn Walker
 */

#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

namespace arc {
    template <class T>
    class Vector2 {
    public:
        T x;
        T y;

        Vector2();

        Vector2(T otherX, T otherY);

        Vector2(const Vector2<T>& otherVect);

        const Vector2<T> operator+(const Vector2<T>& otherVect);

        const Vector2<T> operator-(const Vector2<T>& otherVect);

        const bool operator==(const Vector2<T>& otherVect);

        const bool operator!=(const Vector2<T>& otherVect);
    };

    template <class T>
    Vector2<T>::Vector2() {
        x = 0;
        y = 0;
    }

    template <class T>
    Vector2<T>::Vector2(T otherX, T otherY) {
        x = otherX;
        y = otherY;
    }

    template <class T>
    Vector2<T>::Vector2(const Vector2<T>& otherVect) {
        x = otherVect.x;
        y = otherVect.y;
    }

    template <class T>
    const Vector2<T> Vector2<T>::operator+(const Vector2<T>& otherVect) {
        return Vector2<T>(otherVect.x + this->x, otherVect.y + this->y);
    };

    template <class T>
    const Vector2<T> Vector2<T>::operator-(const Vector2<T>& otherVect) {
        return Vector2<T>(this->x - otherVect, this->y - otherVect);
    }

    template <class T>
    const bool Vector2<T>::operator==(const Vector2<T>& otherVect) {
        return (this->x == otherVect.x) && (this->y == otherVect.y);
    }

    template <class T>
    const bool Vector2<T>::operator!=(const Vector2<T>& otherVect) {
        return !((this->x != otherVect.x) && (this->y == otherVect.y));
    }

    template <class T>
    std::ostream& operator<<(std::ostream& os, const Vector2<T>& vect) {
        os << vect.x << ", " << vect.y;
        return os;
    }
}


#endif
