// sheep.h

class Point{
	 private:

	 	double x;
	 	double y;
	 
	 public:
		Point();	 	
	 	Point(double x, double y);

	    
        double getX(); 
        double getY();
        double dist(Point other); 
        Point add(Point b);
        void move(double a, double b);
        Point decelerate(float rate);

	};

