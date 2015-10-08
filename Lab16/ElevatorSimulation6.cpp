//Lab 16 Completing The Elevator Simulation
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Building.h"
int getArrivalsForThisSecond(double);

int main()
{
  // print student and program information
  cout << "Lab 16 Completing The Elevator Simulation b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  srand(time(0)); rand(); // requires cstdlib and ctime
  Building building;
  
  for (int i = 0; ; i++)
  {
    cout << building.step(getArrivalsForThisSecond(.1)) << endl;
    
    if (!(i % 10)) // pause every 10 seconds
    {
      cout << "Press ENTER to continue, X-ENTER to quit...\n";
      if (cin.get() > 31) break;
    }
  }
  cout<< "DONE: All riders should be gone, and all elevators idle\n";
}

int getArrivalsForThisSecond(double averageRiderArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageRiderArrivalRate); // for n=0 -- requires cmath
  for(double randomValue = (rand() % 1000) / 1000.0; // requires cstdlib AND srand in main
      (randomValue -= probOfnArrivals) > 0.0;
      probOfnArrivals *= averageRiderArrivalRate / ++arrivals);
  return arrivals;
}