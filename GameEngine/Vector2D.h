#pragma once
#include <iostream>
#include <string>

class Vector2D{
public:
	int X, Y;
public:
	Vector2D(float x=0,float y=0):X(x),Y(y){}
	inline Vector2D operator+(Vector2D &other) const {
		return Vector2D(X + other.X, Y + other.Y);
	}

	inline Vector2D operator-(Vector2D &other) const {
		return Vector2D(X - other.X, Y - other.Y);
	}

	inline Vector2D operator*(float scalar) const {
		return Vector2D(X* scalar, Y* scalar);
	}

	void log(std::string msg = "") {
		std::cout << msg << "(X, Y) = " << "(" << X << ", " << Y << ")" << std::endl;
	}
};

