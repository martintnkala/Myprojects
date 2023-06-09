#ifndef satellite_h
#define satellite_h
 
#define TIME 48

#include <cmath>
#include <iostream>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

class Satellite
{
public:
	//Satellite() : pos(21082000, 36515000), v(-2685, 1550), acc(-0.1122, -0.1943) {}
	Satellite() : pos(new Position(21082000, 36515000)), v(new Velocity(-2685, 1550)),
														  acc(new Acceleration(-0.1122, -0.1943)) {}

	void setPosition(double x, double y)
	{
	    pos->setMetersX(x);
	    pos->setMetersY(y);
	}

   
	void setVelocity(double dx, double dy)
	{
	    v->setDx(dx);
	    v->setDy(dy);
	}

   
	void setAcceleration(double ddx, double ddy)
	{
	    acc->setDDx(ddx);
	    acc->setDDy(ddy);
	}

	Position* getPos() { return pos; }
	
	double getPosX()  const { return pos->getMetersX(); }
	double getPosY()  const { return pos->getMetersY(); }
   
	void reCalculate();
	void update();
	Position *pos;
   
private:
	
	Velocity *v;
	Acceleration *acc;
   
};

#endif /* satellite_h */

