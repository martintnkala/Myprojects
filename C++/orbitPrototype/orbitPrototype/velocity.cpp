#include "velocity.h"

void Velocity::reCalculate(Acceleration *acc)
{
	double currDx = getDx();
	double currDy = getDy();
	
	double newDx = currDx + acc->getDDx() * TIME;
	double newDy = currDy + acc->getDDy() * TIME;
	
	setDx(newDx);
	setDy(newDy);
}
