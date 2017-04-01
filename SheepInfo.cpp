#include "SheepInfo.h"

using namespace std;


SheepInfo::SheepInfo(float red, float green, float blue, float range, float vratio, float deceleration, bool herd)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->range = range;
	this->vratio = vratio;
	this->deceleration = deceleration;
	this->herd = herd;
}

float SheepInfo::getRed()
{
	return this->red;
}

float SheepInfo::getGreen()
{
	return this->green;
}

float SheepInfo::getBlue()
{
	return this->blue;
}

float SheepInfo::getRange()
{
	return this->range;
}

float SheepInfo::getVratio()
{
	return this->vratio;
}

float SheepInfo::getDeceleration()
{
	return deceleration;
}

bool SheepInfo::getHerd()
{
	return this->herd;
}
