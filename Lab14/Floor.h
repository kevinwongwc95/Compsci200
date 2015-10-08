//Lab 14 More STL vectors
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Floor_h
#define Floor_h

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Rider.h"

class Floor
{
  const string NAME; // name of floor, for example: Mezzanine
  const int location; // inches above ground level
  vector<Rider> upRiders; // affected by addNewRider, removeUpRiders,...
  vector<Rider> downRiders; // ...and removeDownRiders functions
  
public:
  Floor(const int loc, const char* const name = "unnamed"):location(loc),NAME(name)
  {
  }// name and location (inches above ground) of floor
  
  // inline functions
  int getLocation() const
  {
    return location;
  }
  bool hasRidersWaiting() const
  {
    if(hasUpRiders()==true) return true;
    if(hasDownRiders()==true) return true;
    return false;
  }
  bool hasUpRiders() const
  {
    return (upRiders.size()!=0);
  }
  bool hasDownRiders() const
  {
    return (downRiders.size()!=0);
  }
  int getUpRiderCount() const
  {
    return upRiders.size();
  }
  int getDownRiderCount() const
  {
    return downRiders.size();
  }
  string getName() const
  {
    return NAME;
  }

// non-inline functions
bool isPreferredDirectionUp() const; // based on Rider with smallest ID
void addNewRider(const Rider&); // add to up- or down-vector
vector<Rider> removeUpRiders(int); // int is max #of riders...
vector<Rider> removeDownRiders(int); //...to move onto elevator

// just in case you prefer to use "if (...== *toFloor)"
//  in Elevator::removeRidersForDestinationFloor(), instead of "...== toFloor)"
bool operator==(const Floor& floor) const {return NAME == floor.NAME;}

friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};

#endif
