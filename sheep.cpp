#include <stdlib.h>
#include "Point.h"
#include "SheepInfo.h"

using namespace std;

class Sheep
{

	
	private:

	Point* position;
    Point velocity;
    SheepInfo* info;

	public:

	Sheep()
	{}

	Sheep(int xfield, int yfield, SheepInfo* info)
	{
		float xpos = rand() % (xfield - 100) + 50;
		float ypos = rand() % (yfield - 100) + 50;
		this->position = new Point(xpos, ypos); 
		this->info = info;
	}

	Point get_location()
	{
		return *this->position;
	}
	
	

	void update_position()
	{
		   this->position->add(this->velocity);
	}

	
	void update_velocity()
	{
		//if this.velocity >= unknown amount

			this->velocity.decelerate(this->info->getDeceleration());

		//else stop or change directions	

	}
	
};
