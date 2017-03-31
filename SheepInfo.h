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
    
    SheepInfo(float red, float green, float blue, float range, float vratio, float deceleration, bool herd);
	
	float getRed();
	
	float getGreen();
	
	float getBlue();
	
	float getRange();
	
	float getVratio();
	
	float getDeceleration();
	
	bool getHerd();
	
};
