#include "satellite.h"

void Satellite::reCalculate()
{
	acc->reCalculate(pos);
	v->reCalculate(acc);
}

void Satellite::update()
{
	double x = pos->getMetersX();
	double dx = v->getDx();
	double ddx = acc->getDDx();
	
	double accTimeX = ddx * pow(TIME, 2);
	double newX = x + dx * TIME + (accTimeX / 2);
	pos->setMetersX(newX);
   
	double y = pos->getMetersY();
	double dy = v->getDy();
	double ddy = acc->getDDy();

	double accTimeY = ddy * pow(TIME, 2);
	double newY = y + dy * TIME + (accTimeY / 2);

	pos->setMetersY(newY);
}
