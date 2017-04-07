#ifndef DOG_H
#define DOG_H

#include "Point.h"

class Dog
{

private:

	
	Point* position;
    Point* velocity;
    
    
public:

	Dog();
	
	Point getLocation();

    Point getVelocity();
	
	void updatePosition();
	
	void updateVelocity(Point* p);

};

#endif

