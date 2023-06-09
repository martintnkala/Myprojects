/***************************************
 * POSITION
 ***************************************/
#include"velocity.h"
class Position
{
public:
   Position()                   : x(0.0), y(0.0) {}
   Position(double x, double y) : x(x), y(y)     {}

   double getX() const { return x;    }
   double getY() const { return y;    }
   void setX(double x) { this->x = x; }
   void setY(double y) { this->y = y; }

   Position& add(const Velocity& v, double t)
   {
      x += v.getDx() * t;
      y += v.getDy() * t;
      return *this;
   }

   Position& addMany(const Velocity& v, double t, int count)
   {
      for (int i = 0; i < count; i++)
         add(v, t);
      return *this;
   }
private:
   double x;
   double y;
};

