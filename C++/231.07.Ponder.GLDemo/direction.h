//
//  direction.h
//  Lab07
//
//  Created by Martin Nkala on 6/2/23.
//

#ifndef direction_h
#define direction_h

#define TIME 48

#include <cmath>
#include <iostream>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

class Direction
{
public:
   Direction() : pos(0.0, 0.0), v(0.0, 0.0), acc(0.0, 0.0) {}
   
   Direction(Position pos, Velocity v, Acceleration acc) {
      this->pos = pos;
      this->v = v;
      this->acc = acc;
   }
   
   void setPosition(float x, float y)
   {
      pos.setMetersX(x);
      pos.setMetersY(y);
   }
   
   void setVelocity(float dx, float dy)
   {
      v.setDx(dx);
      v.setDy(dy);
   }
   
   void setAcceleration(float ddx, float ddy)
   {
      acc.setDDx(ddx);
      acc.setDDy(ddy);
   }
   
   void update()
   {
      float x = pos.getMetersX();
      float dx = v.getDx();
      float ddx = acc.getDDx();
      float newX = x * dx * TIME + (ddx * pow(TIME, 2));
      pos.setMetersX(newX);
      
      float y = pos.getMetersY();
      float dy = v.getDy();
      float ddy = acc.getDDy();
      float newY = y * dy * TIME + (ddy * pow(TIME, 2));
      pos.setMetersY(newY);
      
      
   }
   
private:
   Position pos;
   Velocity v;
   Acceleration acc;
   
   
};

#endif /* direction_h */
