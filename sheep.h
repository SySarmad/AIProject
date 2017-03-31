// sheep.h

#define Sheep
#include "Point.h"
#include "color.h"

class Sheep
{

private:

	
	Point position;
    Point velocity;
    Color color;
    float range;
    float vratio;
    float deceleration;
    bool herd;

public:

	Sheep(Color color, float range, float vratio, float deceleration, bool herd);
	
	Point get_locaton();

	void update_position();
	
	void update_velocity();

};
