class Sheep
{
	 
	class Color{
	private:
		float red;
    	float blue;
    	float green;
	
	public:
		Color(float red = 0.0f; float blue = 0.0f; float green = 0.0f)
		{
			this.red = red;
			this.blue = blue;
			this.green = green;
		}


	}
private:

	Point position = new Point();
    Point velocity = new Point();
    Color color = new Color();
    float range;
    float vratio;
    float deceleration;
    bool herd;

public:

	Sheep(Color color, float range, float vratio, float deceleration, bool herd)
	{
		// this.position = random (x, y) values 
		this.color = color;
		this.range = range;
		this.vratio = vratio;
		this.deceleration = deceleration;
		this.herd = herd;
	}

	Point get_locaton()
	{
		return this.p
	}

	float* get_color()
	{
		return [this.color.red, this.color.blue, this.color.green];;

	void update_position()
	{
		   this.p.add(this.velocity)
	}

	
	void update_velocity()
	{
		//if this.velocity >= unknown amount

			this.velocity.deceleration(this.deceleration);

		//else stop or change directions	

	}

};
