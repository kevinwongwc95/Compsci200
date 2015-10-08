//Lab 15 Using The STL
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
using std::ostream;

#include <vector>
using std:: vector;

class Elevator;
class Floor;

class Building
{
public:
  Building();
  int getFloorCount() const
  {
    return (floors.size()); // return #of floors in the vector of Floor*'s
  }
  int getElevatorCount() const
  {
    return (elevators.size()); // return #of elevators in the vector of Elevator*'s
  }
  const Floor& getFloor(int index) const
  {
    return *floors[index]; // return a reference to the "indexth" floor
  }
  const Elevator& getElevator(int index) const
  {
    return *elevators[index]; // return a reference to the "indexth" elevator
  }
  
  friend ostream& operator<<(ostream&, const Building&);
  
  Building& step(int);
  void getDifferentInts(int,int&,int&); //random number generator function
  ~Building(); //destructor

private:
  int Time; //time counters
  vector<Floor*> floors;
  vector<Elevator*> elevators;
};
#endif
