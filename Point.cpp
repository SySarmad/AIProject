class Point{
	 private:

	 	double x
	 	double y
	 public:
	 	Point(double x = 0.0, double y= 0.0)
	 	{
	 		this.x = x;
	 		this.y = y;
	 	}

	 // Extractors.
        double x() { return this.x; }
        double y() { return this.y; }

        // Distance to another point.  Pythagorean thm.
        double dist(Point other) {
                double xd = this.x - other.x;
                double yd = this.y - other.y;
                return sqrt(xd*xd + yd*yd);
        }

        // Add or subtract two points.
        Point add(Point b)
        {
                return Point(this.x + b.x, this.y + b.y);
        }

        // Move the existing point.
        void move(double a, double b)
        {
                this.x += a;
                this.y += b;
        }

        Point decelerate(float rate)
        {
                return new Point(this.x*rate, this.y*rate);

        }

	};