// This program demonstrates how you can define and use functions.
// This program duplicates the functionality of MathFuncs.cpp

#include <iostream>          // for std::cout
#include <cmath>             // for floor(x),ceil(x),fabs(x) & sqrt(x)
using namespace std;         // supports cout

// precondition:  double argument assigned a value
// postcondition: floor, ceil, fabs and sqrt of argument is computed
//                and printed out to standard output
int compute_and_print( double d );

int main( )
{
  double value = 0.0;
 
  cout << "Please enter a value for computations: " << endl;
  cin  >> value;
 
  compute_and_print( value );
  return 0;
}
 
int compute_and_print( double d ) {
  cout << "\t floor_value = " << floor( d ) << endl;
  cout << "\t ceil_value  = " << ceil( d )  << endl;
  cout << "\t fabs_value  = " << fabs( d )  << endl;
  cout << "\t sqrt_value  = " << sqrt( d )  << endl;
 
  return 0;
}
 
