#include "angle.h"
#define PI       3.14159265  // Definition of pi
using namespace std;

/*****************************
 * Header File:
 *    Angle.cpp
 * Author:
 *    Caleb Nuttal, Martin Nkala
 * Summary:
 *    This class validates and convert angles.
 *****************************/



// These are setter methods for degrees and radians.
/*****************************
 * SET DEGREES.
 * Sets Degrees.
 *****************************/
void Angle::setDegrees(double degrees)
{
   this->radians = convertToRadians(degrees);
   normalize();
}

/*****************************
 * SET RADIANS.
 * Sets Radians.
 *****************************/
void Angle::setRadians(double radians)
{
   this->radians = radians;
   normalize();
}

/*****************************
 * GET DEGREES.
 * Gets Degrees.
 *****************************/
double Angle::getDegrees()const
{
   double radians = getRadians();
   return convertToDegrees(radians);
}

/*****************************
 * GET RADIANS.
 * Gets Radians.
 *****************************/
double Angle::getRadians()const
{
   return radians;
}

/*****************************
 * DISPLAY.
 * Displays the value in degrees, to 1 decimal place of accuracy.
 *****************************/
void Angle::display()const
{
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);
   cout << getDegrees() << endl;
}

/*****************************
 * CONVERT TO DEGREES.
 * Converts Radians to Degrees.
 *****************************/
double Angle::convertToDegrees(double radians) const
{
   return (radians * 180.0) / PI ;
}

/*****************************
 * CONVERT TO RADIANS.
 * Converts Degrees to Radians.
 *****************************/
double Angle::convertToRadians(double degrees) const
{
   return (degrees * PI) / 180.0; // radians = 2pi * degrees / 360
}

/*****************************
 * NORMALIZE.
 * Ensures that the angle is between 0 and 360 degrees.
 *****************************/
void Angle::normalize()
{
   if (this->radians > 2.0 * PI)
   {
      int overlap = this->radians / (2.0 * PI);
      this->radians -=(overlap * 2.0 * PI);
      
   }
   
   // Calculating for the negative radian value.
   else if (this->radians < 0)
   {
      int overlap = -this->radians / (2.0 * PI);
      this->radians = this->radians + (overlap * 2.0 * PI);
      this->radians += 2.0 * PI;
   }
}


