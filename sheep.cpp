#include <stdlib.h>
#include "Point.h"
#include "SheepInfo.h"
#include "sheep.h"
#include <math.h>

using namespace std;

Sheep::Sheep()
{}

Sheep::Sheep(int xfield, int yfield, SheepInfo* info)
{
	float xpos = rand() % (xfield * 2 - 200) + 100 - xfield;
	float ypos = rand() % (yfield * 2 - 200) + 100 - yfield;
	this->position = new Point(xpos, ypos);
	this->velocity = new Point(0.0, 0.0); 
	//this->velocity = new Point(-xpos / sqrt(xpos * xpos + ypos * ypos), -ypos / sqrt(xpos * xpos + ypos * ypos));
	this->info = info;
}

Point Sheep::get_location()
{
	return *this->position;
}

float* Sheep::getColor()
{
	float* color = new float[3];
	color[0] = this->info->getRed();
	color[1] = this->info->getGreen();
	color[2] = this->info->getBlue();
	return color;
}

void Sheep::dogCheck()
{
	//check for dog
	//if dog, update velocity based on dog
	//else nothing?
	this->update_position();
}

void Sheep::update_position()
{
	   this->position->add(this->velocity);
}


void Sheep::update_velocity()
{
	//if this.velocity >= unknown amount

		this->velocity->decelerate(this->info->getDeceleration());

	//else stop or change directions	

}

