#include <iostream>
using namespace std;

#include "Time.h"

int main()
{
  Time test;
  test.setTime(3,20,45);
  cout<<"Hour "<<test.getHour()<<endl;
  cout<<"Minute "<<test.getMinute()<<endl;
  cout<<"Second "<<test.getSecond()<<endl;
  
  test.printStandard();
  cout<<endl;
  test.printUniversal();
  
}