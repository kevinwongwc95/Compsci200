//Lab 10b Using vectors
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Elevator_h
#define Elevator_h

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

#include "Rider.h"

class Floor;

class Elevator
{
  
private:
  
  // class-defined constants
  static int elevatorID; // initialize to zero; use to assign unique ID to each elevator
  static const int IDLE; // a unique numeric code
  static const int UP; // another unique numeric code
  static const int DOWN; // yet another unique numeric code
  
  // private member variables
  const int ID; // a unique identifier
  const int capacity; // max number of riders, set in constructor
  const int speed; // inches per second, up or down, set in constructor
  const Floor* toFloor; // destination floor, initialized in constructor to zero
  int location; // inches above ground level, initialized in constructor based on starting floor
  int direction; // equal to IDLE, UP, DOWN, initialized to IDLE in constructor
  bool doorOpen; // initialized to true in constructor
  vector <Rider> riders;//vector of riders
  
public:
  
  Elevator(const int, const int, const Floor&); // capacity, speed, and starting floor
  
  bool isDoorOpen() const  // returns value of doorOpen
  {
    return doorOpen;
  }
  
  bool isIdle() const // returns true if direction is IDLE
  {
    if(direction==0)
    {
      return true;
    }
    return false;
  }
  bool isDirectionUp() const // returns true if direction is UP
  {
    if(direction==1)
    {
      return true;
    }
    return false;
  }
  bool isDirectionDown() const // returns true if direction is DOWN
  {
    if(direction==-1)
    {
      return true;
    }
    return false;
  }
  void closeDoor() // set doorOpen to false
  {
    doorOpen=false;
  }
  void openDoor()// set doorOpen to true
  {
    doorOpen=true;
  }
  void setIdle()// set direction to IDLE
  {
    direction=0;
  }
  void setDirectionUp()// set direction to UP
  {
    direction=1;
  }
  void setDirectionDown() // set direction to DOWN
  {
    direction=-1;
  }
  void moveUp()// increment location by #inches per second speed of the elevator
  {
    location=location+speed;
  }
  void moveDown()// decrement location by #inches per second speed of the elevator
  {
    location=location-speed;
  }
  void setDestination(const Floor* floor)// set toFloor pointer
  {
    toFloor=floor;
  }
  const Floor& getDestination() const // return reference to toFloor (warning!)
  {
    return *toFloor;
  }
  int getLocation() const // return location value
  {
    return location;
  }
  bool hasADestination() const // return false if toFloor is zero
  {
    if(toFloor==0)
    {
      return false;
    }
    return true;
  }
  
  bool hasRiders() const
  {
    if(riders.size()==0)
    {
      return false;
    }
    return true;
  }
  
  int getRiderCount() const
  {
    return riders.size();
  }
  
  int getCapacity() const
  {
    return capacity;
  }
  
  int getAvailableSpace() const
  {
    return (capacity-riders.size());
  }
  
  // non-inline functions
  bool isNearDestination() const; // true if distance to destination is less than OR EQUAL TO the speed
  void moveToDestinationFloor(); // set location to that of destination floor (if there is one)
  
  vector<Rider> removeRidersForDestinationFloor();
  void addRiders(const vector<Rider>&);
  void setDestinationBasedOnRiders();
  
  // friend function
  friend ostream& operator<<(ostream&, const Elevator&);
};

#endif