// sheep.h

#include "Point.h"
#include "SheepInfo.h"

class Sheep
{

private:

	
	Point* position;
    Point velocity;
    SheepInfo* info;
    
    
public:

	Sheep();

	Sheep(int xfield, int yfield, SheepInfo* info);
	
	Point get_location();

	void update_position();
	
	void update_velocity();

};


