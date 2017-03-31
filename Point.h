// sheep.h

#define Point

class Point{
	 private:

	 	double x;
	 	double y;
	 
	 public:
	 	
	 	Point();

	    
        double getX(); 
        double getY();
        double dist(Point other); 
        Point add(Point b);
        void move(double a, double b);
        Point decelerate(float rate);

	};
