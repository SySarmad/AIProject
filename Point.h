#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <cstdlib>

class Point{
	 private:

	 	float x;
	 	float y;
	 
	 public:
		Point();
	 	Point(float x, float y);

	    
        float getX(); 
        float getY();
        float dist(Point other); 
        void add(Point* b);
        void move(float a, float b);
        Point* decelerate(float rate);

};

#endif
