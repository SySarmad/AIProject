using namespace std;

class SheepInfo
{
	float red;
	float green;
	float blue;
    float range;
    float vratio;
    float deceleration;
    bool herd;
    
public:
    
    SheepInfo(float red, float green, float blue, float range, float vratio, float deceleration, bool herd)
	{
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->range = range;
		this->vratio = vratio;
		this->deceleration = deceleration;
		this->herd = herd;
	}
	
	float getRed()
	{
		return this->red;
	}
	
	float getGreen()
	{
		return this->green;
	}
	
	float getBlue()
	{
		return this->blue;
	}
	
	float getRange()
	{
		return this->range;
	}
	
	float getVratio()
	{
		return this->vratio;
	}
	
	float getDeceleration()
	{
		return deceleration;
	}
	
	bool getHerd()
	{
		return this->herd;
	}
	
	
};
