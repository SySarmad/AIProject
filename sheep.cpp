#include "Point.h"
#include "color.h"

class Sheep
{

	
	private:

	Point position = Point();
    Point velocity = Point();
    Color color = Color();
    float range;
    float vratio;
    float deceleration;
    bool herd;

	public:

	Sheep(Color color, float range, float vratio, float deceleration, bool herd)
	{
		// this.position = random (x, y) values 
		this->color = color;
		this->range = range;
		this->vratio = vratio;
		this->deceleration = deceleration;
		this->herd = herd;
	}

	Point get_locaton()
	{
		return this->position;
	}

	float* get_color()
	{
		return new float[3]{this->color.red, this->color.blue, this->color.green};
		
	}
	
	

	void update_position()
	{
		   this->position.add(this->velocity);
	}

	
	void update_velocity()
	{
		//if this.velocity >= unknown amount

			this->velocity.decelerate(this->deceleration);

		//else stop or change directions	

	}
	
};
