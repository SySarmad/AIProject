#ifndef SHEEP_H
#define SHEEP_H

#include <stdlib.h>
#include "Point.h"
#include "SheepInfo.h"

class Sheep
{

private:

	
	Point* position;
    Point* velocity;
    SheepInfo* info;
    
    
public:

	Sheep();

	Sheep(int xfield, int yfield, SheepInfo* info);
	
	Point get_location();
	
	float* getColor();
	
	void dogCheck(Point d, Point dv);

	void update_position();
	
	void update_velocity();

};

#endif
