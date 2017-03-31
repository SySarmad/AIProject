#include <stdlib.h>
#include "Point.h"
#include "color.h"


class Sheep
{

	
	private:

	Point* position;
    Point velocity;
    Color color;
    float range;
    float vratio;
    float deceleration;
    bool herd;

	public:

	Sheep(int xfield, int yfield, Color color, float range, float vratio, float deceleration, bool herd)
	{
		float xpos = rand() % (xfield - 100) + 50;
		float ypos = rand() % (yfield - 100) + 50;
		this->position = new Point(xpos, ypos); 
		this->color = color;
		this->range = range;
		this->vratio = vratio;
		this->deceleration = deceleration;
		this->herd = herd;
	}

	Point get_locaton()
	{
		return *this->position;
	}

	float* get_color()
	{
		float* colors = new float[3];
		colors[0] = this->color.red;
		colors[1] = this->color.blue;
		colors[2] = this->color.green;
		return colors;
		
	}
	
	

	void update_position()
	{
		   this->position->add(this->velocity);
	}

	
	void update_velocity()
	{
		//if this.velocity >= unknown amount

			this->velocity.decelerate(this->deceleration);

		//else stop or change directions	

	}
	
};
