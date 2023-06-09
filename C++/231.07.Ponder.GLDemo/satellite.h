//
//  satellite.h
//  Lab07
//
//  Created by Martin Nkala on 6/2/23.
//

#ifndef satellite_h
#define satellite_h
#include "direction.h"

class Satellite
{
public:
   Satellite(Position pos, Velocity v, Acceleration acc) {
      Direction dir(pos, v, acc);
   }
   Satellite(Direction dir) {
      this->dir = dir;
   }
   
private:
   Direction dir;
   
};

#endif /* satellite_h */
