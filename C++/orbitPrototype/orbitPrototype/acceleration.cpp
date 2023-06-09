#include "acceleration.h"

double Acceleration::getAngle(Position *pos)
{
	double x = pos->getMetersX();
	double y = pos->getMetersY();
 
	
	double angle = atan2(x, y);
	
	return angle;
	
}

double Acceleration::getGravityHeight()
{
	double sum = RADIUS + HEIGHT;
	double base = RADIUS / sum;
	double gHeight = ACC * pow(base, 2);

	return gHeight;
}


void Acceleration::calculate(double angle, double gHeight)
{
	double sinRad = sin(angle);
	double sinDeg = sinRad * (180/PI);

	double newDDx = gHeight * sinDeg;
	cout << newDDx << endl;
	
	double cosRad = cos(angle);
	double cosDeg = cosRad * (180/PI);
	double newDDy = gHeight * cosDeg;
	cout << newDDy << endl;
	
	setDDx(newDDx);
	setDDy(newDDy);
}


void Acceleration::reCalculate(Position *pos)
{
	double gHeight = getGravityHeight();
	double angle = getAngle(pos);
	
	double newDDx = gHeight * sin(angle);
	double newDDy = gHeight * cos(angle);
	
	setDDx(newDDx);
	setDDy(newDDy);
}
