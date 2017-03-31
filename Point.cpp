#include <math.h>
#include <cstdlib>

class Point{
	 private:

	 	float x;
	 	float y;
	 	
	 public:
		
		Point()
	 	{
	 		this->x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));
	 		this->y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));
	 	}
	 
	 	Point(float x = 0.0, float y= 0.0)
	 	{
	 		this->x = x;
	 		this->y = y;
	 	}

	 // Extractors.
        float getX() 
        { 
			return (this->x > 0.0) ? (this->x + 0.5) : (this->x - 0.5); 
		}
		
        double getY() 
        { 
			return (this->y > 0.0) ? (this->y + 0.5) : (this->y - 0.5); 
		}

        // Distance to another point.  Pythagorean thm.
        float dist(Point other) {
                float xd = this->x - other.x;
                float yd = this->y - other.y;
                return sqrt(xd*xd + yd*yd);
        }

        // Add or subtract two points.
        Point add(Point b)
        {
                return Point(this->x + b.x, this->y + b.y);
        }

        // Move the existing point.
        void move(float a, float b)
        {
                this->x += a;
                this->y += b;
        }

        Point* decelerate(float rate)
        {
                return new Point(this->x*rate, this->y*rate);

        }

	};
