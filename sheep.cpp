#include <stdlib.h>
#include <iostream>
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

void Sheep::dogCheck(Point d, Point dv)
{
	if(this->position->dist(d) < this->info->getRange())
	{
		float vr = this->info->getVratio();
		this->velocity->move(dv.getX() * vr, dv.getY() * vr);
	}
}

void Sheep::update_position()
{
	this->position->add(this->velocity);
	this->update_velocity();
}


void Sheep::update_velocity()
{
	if(this->velocity->magnitude() > 0.01)
	{
		this->velocity->decelerate(this->info->getDeceleration());
	}
	else
	{
		this->velocity->stop();
	}
}

