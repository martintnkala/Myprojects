//
//  velocity.h
//  Lab07
//
//  Created by Martin Nkala on 6/2/23.
//

#ifndef velocity_h
#define velocity_h
#define TIME 48

#include "acceleration.h"

class Velocity
{
public:
   Velocity(): dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy) {
      this->dx = dx;
      this->dy = dy;
   }
   
   void setDx(double dx) { this->dx = dx; }
   void setDy(double dy) { this->dy = dy; }
   
   double getDx() const { return dx; }
   double getDy() const { return dy; }
   
   void reCalculate(Acceleration &acc) {
      double currDx = getDx();
      double currDy = getDy();
      
      double newDx = currDx + acc.getDDx() * TIME;
      double newDy = currDy + acc.getDDy() * TIME;
      
      setDx(newDx);
      setDy(newDy);
      
   }
   
private:
   double dx;
   double dy;
}

#endif /* velocity_h */
