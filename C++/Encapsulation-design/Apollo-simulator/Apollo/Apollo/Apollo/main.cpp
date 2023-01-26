//
//  main.cpp
//  Apollo
//
//  Created by Martin Nkala on 1/12/23.
//

/*************************************************************
 * 1. Name:
 *      Caleb Nuttall, Martin Nkala
 * 2. Assignment Name:
 *      Practice 02: Physics simulator
 * 3. Assignment Description:
 *      Compute how the Apollo lander will move across the screen
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was figuring out how to make our second
 *      prompt for the  angle more dynamic.
 * 5. How long did it take for you to complete the assignment?
 *      Close to two hours each.
 **************************************************************/

#include <iostream>  // for CIN and COUT
#include <cmath>
#include <assert.h>
using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)
#define PI       3.14159265  // Definition of pi

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
double computeDistance(double s, double v, double a, double t)
{
   return s + (v * t) + (0.5 * a * t * t);
}

/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
double computeAcceleration(double f, double m)
{
   return f / m;
}

/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
double computeVelocity(double v, double a, double t)
{
   return v + (a * t);
}


/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
double computeVerticalComponent(double a, double total)
{
   return cos(a) * total;
}

/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
double computeHorizontalComponent(double a, double total)
{
   return sin(a) * total;
}

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
double computeTotalComponent(double x, double y)
{
   return sqrt(x * x + y * y);
}


/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double radFromDeg(double d)
{
   return (d * PI) / 180; // radians = 2pi * degrees / 360
}

/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
double prompt(string message)
{
   double input;
   cout << message;
   cin >> input;
   return input;
}


/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
int main()
{
   // Prompt for input and variables to be computed
   double dx = prompt("What is your horizontal velocity (m/s)? ");
   double dy = prompt("What is your vertical velocity (m/s)? ");
   double x = 0.0;
   double y = prompt("What is your altitude (m)? ");
   double t = 1;
   double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
   double aRadians = radFromDeg(aDegrees);                                              // Angle in radians
   double accelerationThrust = computeAcceleration(THRUST, WEIGHT);                     // Acceleration due to thrust
   double ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);         // Horizontal acceleration due to thrust
   double ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);           // Vertical acceleration due to thrust
   double ddx = ddxThrust;                                                              // Total horizontal acceleration
   double ddy = ddyThrust + GRAVITY;                                                    // Total vertical acceleration
   double v;                                                                            // Total velocity
   
   
   // Display output five times
   cout << "\nFor the next 5 seconds with the main engine on, the position of the lander is:\n\n";
   for (int totalTime = 1; totalTime <= 10; totalTime++)
   {
      if (totalTime == 6)
      {
         aDegrees = prompt("\nWhat is the new angle of the LM where 0 is up (degrees)? ");
         aRadians = radFromDeg(aDegrees);
         accelerationThrust = computeAcceleration(THRUST, WEIGHT);                     // Acceleration due to thrust
         ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);         // Horizontal acceleration due to thrust
         ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);           // Vertical acceleration due to thrust
         ddx = ddxThrust;                                                              // Total horizontal acceleration
         ddy = ddyThrust + GRAVITY;
         cout << "\nFor the next 5 seconds with the main engine on, the position of the lander is:\n\n";
      }

      // Compute the new velocity components
      dx = computeVelocity(dx, ddx, t);
      dy = computeVelocity(dy, ddy, t);
      v = computeTotalComponent(dx, dy);


      // Compute the new distance components
      x = computeDistance(x, dx, ddx, t);
      y = computeDistance(y, dy, ddy, t);


      // Output
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);

      
      cout << totalTime
         << "s - x,y:(" << x << ", " << y
         << ")m  dx,dy:(" << dx << ", " << dy << ")m/s  speed:"
         << v << "m/s  angle:"
         << aDegrees << "deg\n";
   }


   return 0;
}

