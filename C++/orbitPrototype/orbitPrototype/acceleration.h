#ifndef acceleration_h
#define acceleration_h

#define RADIUS 6378000
#define HEIGHT 35786000
#define ACC -9.8067
#define PI 3.141529

#include <cmath>
#include <iostream>
#include "position.h"

using namespace std;

class Acceleration
{
public:
	//Acceleration(): ddx(0.0), ddy(0.0) {}
    Acceleration(): ddx(-0.1122), ddy(-0.1943) {}

	Acceleration(double x, double y) {
		
		setDDx(x);
		setDDy(y);

	}
   
    void setDDx(double ddx) { this->ddx = ddx; }
    void setDDy(double ddy) { this->ddy = ddy; }
    
    double getDDx() const { return ddx; }
    double getDDy() const { return ddy; }
	
	double getAngle(Position *pos);
	double getAngle(double x, double y);
	double getGravityHeight();
   
	void calculate(double angle, double gHeight);
	void reCalculate(Position *pos);

   
private:
   double ddx; // change in change in x
   double ddy; // change in change in y
   
};

#endif /* acceleration_h */
