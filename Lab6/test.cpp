#include <iostream>
using namespace std;

#include "Time.h"

int main ()
{
  Time t;
  t.setHour(3).setMinute(4).setSecond(45);

  
  t.printUniversal();
}