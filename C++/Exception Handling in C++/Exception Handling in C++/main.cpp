#include <iostream>


/************************************
 * What causes exceptions?
 *  1. Insufficient resources.
 *  2. Missing resources.
 *  3. Invalid operations.
 *  4. Range Violations.
 *  5. underflows and overflows.
 *  6. illegal data and many others.
 *********************************************/

/***********************
 * MPGCALCULATOR function.
 ********************************/
double mpgCalculator (double miles, double gallons)
{
   double milesPerGallon = miles/gallons;
   
   return milesPerGallon;
}

/***********************
 * MAIN function.
 * Exception handling using IF THEN logic.
 ********************************/
//int main() {
//
//   double m{};
//   double g{};
//
//   std:: cout << " Enter Miles: ";
//   std:: cin >> m;
//   std:: cout << " Enter number of Gallons: ";
//   std:: cin >> g;
//
//   if (g != 0) {
//      double result {mpgCalculator(m, g)};
//
//      std:: cout << "Result: " << result << std:: endl;
//   }
//   else
//   {
//      std:: cerr << "Can't divide by zero.";
//   }
//   return 0;
//}

/***********************
 * MAIN
 * Exception handling using TRY CATCH.
 *
 ********************************/
int main() {
   
   double m{};
   double g{};
   
   std:: cout << " Enter Miles: ";
   std:: cin >> m;
   std:: cout << " Enter number of Gallons: ";
   std:: cin >> g;
   
   try{
      if (g == 0)
      {
         throw 0;
      }
      double result {mpgCalculator(m, g)};
      
      std:: cout << "Result: " << result << std:: endl;
   }
   catch(int &e)// catch by reference. Good practice
   {
      std:: cerr << "Error! can't divide miles by Zero.\n";
   }
   return 0;
}
