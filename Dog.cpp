#include "Point.h"
#include "Dog.h"

Dog::Dog()
{
	this->position = new Point();
	this->velocity = new Point();
}

Point Dog::getLocation()
{
	return *this->position;
}

Point Dog::getVelocity()
{
	return *this->velocity;
}

void Dog::updatePosition()
{
	this->position->add(this->velocity);
}

void Dog::updateVelocity(Point* p)
{
	delete this->velocity;
	this->velocity = p;
}

