//
//  acceleration.h
//  Lab07
//
//  Created by Martin Nkala on 6/2/23.
//

#ifndef acceleration_h
#define acceleration_h
#include <cmath>
#include <iostream>
#include "position.h"
#define RADIUS 6378000
#define HEIGHT 35786000
#define ACC -9.8067
#define PI 3.141529

class Acceleration
{
public:
   Acceleration(): ddx(0.0), ddy(0.0) {}
   Acceleration(double ddx, double ddy) {
      this->ddx = ddx;
      this->ddy = ddy;
   }
   
   void setDDx(double ddx) { this->ddx = ddx; }
   void setDDy(double ddy) { this->ddy = ddy; }
   
   double getDDx() const { return ddx; }
   double getDDy() const { return ddy; }
   double getAngle(Position &pos)
   {
      double x = pos.getMetersX();
      double y = pos.getMetersY();
//      double convertToRad = ((30/360) * (2 * PI));
      double radians = atan2(y, x);
      double degrees = radians * (180/PI);
      
      return degrees;
      
   }
   
   double getGravityHeight()
   {
      double base = (RADIUS/(RADIUS + HEIGHT));
      double gHeight = ACC * pow(base, 2);
      return gHeight;
   }
   
   void reCalculate()
   {
      double gHeight = getGravityHeight();
      double angle = getAngle();
      double newDDx = gHeight * sin(angle);
      double newDDy = gHeight * cos(angle);
      setDDx(newDDx);
      setDDy(newDDy);
   }

   
private:
   double ddx;
   double ddy;
   
};

#endif /* acceleration_h */
