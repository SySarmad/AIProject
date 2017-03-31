// sheep.h

#ifndef sheep_h
#define sheep_h

class Sheep
{
	class Color{
	private:
		float red;
    	float blue;
    	float green;
	
	public:
		Color(float red; float blue; float green)
		{
	}
private:

	Point position;
    Point velocity;
    Color color;
    float range;
    float vratio;
    float deceleration;
    bool herd;

public:

	Sheep(Color color, float range, float vratio, float deceleration, bool herd)

	Point get_locaton()

	void update_position()
	
	void update_velocity()

};
