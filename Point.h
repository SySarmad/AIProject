// sheep.h

class Point{
	 private:

	 	float x;
	 	float y;
	 
	 public:
		Point();	 	
	 	Point(int range);

	    
        float getX(); 
        float getY();
        float dist(Point other); 
        Point add(Point b);
        void move(double a, double b);
        Point decelerate(float rate);

	};

