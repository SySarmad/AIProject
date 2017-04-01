#include <math.h>
#include <cstdlib>
#include "Point.h"

using namespace std;



// Extractors.
float Point::getX() 
{ 
	return (this->x > 0.0) ? (this->x + 0.5) : (this->x - 0.5); 
}

float Point::getY() 
{ 
	return (this->y > 0.0) ? (this->y + 0.5) : (this->y - 0.5); 
}

Point::Point()
{
	
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

// Distance to another point.  Pythagorean thm.
float Point::dist(Point other) {
		float xd = this->x - other.x;
		float yd = this->y - other.y;
		return sqrt(xd*xd + yd*yd);
}

// Add or subtract two points.
Point Point::add(Point b)
{
		return Point(this->x + b.x, this->y + b.y);
}

// Move the existing point.
void Point::move(float a, float b)
{
		this->x += a;
		this->y += b;
}

Point* Point::decelerate(float rate)
{
		return new Point(this->x*rate, this->y*rate);

}
