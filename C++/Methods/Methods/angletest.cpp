#include <stdio.h>
#include "angle.h"
#define PI       3.14159265  // Definition of pi
using namespace std;

/*****************************
 * Header File:
 *    angleTest.cpp
 * Author:
 *    Caleb Nuttal, Martin Nkala
 * Summary:
 *    This file is to test the angle class.
 *****************************/

/*****************************
 * MAIN
 * Test the functionality of Angle class.
 *****************************/
int main()
{
   // Test cases.
   double degreesList[9] = {0.0, 360.0, 180.0, 375.0, 860.0, -360.0, -375.0, -180.0, -860.0};
   double radiansList[9] = {0.0, 2.0 * PI, PI, 5.0 * PI/2.0, 9.0 * PI,-2.0 * PI, -PI, -5.0 * PI/2.0, -9.0 * PI };
   
   // Creating an instance of the Angle Object.
   Angle angle;
   
   //   Looping through the degrees list.
   for(double degrees: degreesList)
   {
      cout << "\nDegrees test case: " << degrees << endl;
      
      angle.setDegrees(degrees);
      
      cout << "Get Degrees: " << angle.getDegrees() << endl;
      
      angle.display();
      
      cout << "Press Enter for next test case. ";
      
      cin.ignore();
   }
   
   //   Looping through the radians list.
   for(double radians : radiansList)
   {
      cout << "\nRadians test case: " << radians << endl;
      
      angle.setRadians(radians);
      
      cout << "Get Radians: " << angle.getRadians() << endl;
      
      angle.display();
      
      cout << "Press Enter for next test case. ";
      
      cin.ignore();
   }
   
   cout << "\nEnd of test cases." << endl;

}
