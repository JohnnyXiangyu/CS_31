// This program demonstrates how you can use the standard math
// functions available in <cmath> described in Appendix 4.

#include <iostream>          // for std::cout
#include <cmath>             // for floor(x),ceil(x),fabs(x) & sqrt(x)
using namespace std;         // supports cout

int main( )
{
  double value = 0.0, floor_value, ceil_value, fabs_value, sqrt_value;
 
  cout << "Please enter a value for computations: " << endl;
  cin  >> value;
 
  floor_value = floor( value );
  ceil_value  = ceil( value );
  fabs_value  = fabs( value );
  sqrt_value  = sqrt( value );
  
  cout << "\t floor_value = " << floor_value << endl;
  cout << "\t ceil_value  = " << ceil_value  << endl;
  cout << "\t fabs_value  = " << fabs_value  << endl;
  cout << "\t sqrt_value  = " << sqrt_value  << endl;
  
  return 0;
}

