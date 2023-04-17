#pragma once
#include <iostream>
#include "Vector2D.h"
class Transform {
public :
	float X, Y;
	Transform(float x = 0,float y=0):X(x),Y(y){}
	void log(std::string msg = "") {
		std::cout << msg << "(X, Y) = " << "(" << X << ", " << Y << ")" << std::endl;
	}
private:
	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float y) { Y += y; }
	inline void TranslateY(Vector2D v) { X+=v.X,Y += v.Y; }

};