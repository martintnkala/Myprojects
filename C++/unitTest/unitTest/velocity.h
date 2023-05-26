/************************************
  * VELOCITY
  ************************************/
class Velocity
{
   public:
      Velocity()                     : dx(0.0), dy(0.0) {}
      Velocity(double dx, double dy) : dx(dx),  dy(dy)  {}

      double getDx() const  { return dx;     }
      double getDy() const  { return dy;     }
      void setDx(double dx) { this->dx = dx; }
      void setDy(double dy) { this->dy = dy; }
   private:
      double dx;
      double dy;
};

