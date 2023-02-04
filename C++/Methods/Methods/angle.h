
#pragma once
#include <stdio.h>
#include <iostream>

/*****************************
 * Header File:
 *    Angle.h
 * Author:
 *    Caleb Nuttal, Martin Nkala
 * Summary:
 *    This class validates and convert angles.
 *****************************/

/*************************
 * ANGLE
 * A single Angle.
 *************************/
class Angle
{
   
private:
   // This attribute will contain the radian value.
   double radians;

public:
   
   // Default Constructor.
   Angle(): radians(0.0){};
   
   // Non-default Constructor.
   Angle(double degrees);
   
   // Copy Constructor.
   Angle(const Angle &rhs)
   {
      radians = rhs.radians;
   }
   
   // These are setter methods for degrees and radians.
   void setDegrees(double degrees);
   void setRadians(double radians);
   
   // These are getter methods for degrees and radians.
   double getDegrees() const;
   
   double getRadians() const;
   
   // Displays the value in degrees, to 1 decimal place
   //of accuracy.
   void display() const;
   
private:
   
   double convertToDegrees(double radians) const;
   
   double convertToRadians(double degrees) const;
   
   void normalize();
};
