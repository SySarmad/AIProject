// sheep.h

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
        Point add(Point b);
        void move(double a, double b);
        Point decelerate(float rate);

	};

