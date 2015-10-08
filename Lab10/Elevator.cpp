//Lab 10b Using vectors
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::ostream;
using std::endl;

#include <cstdlib>
using std::abs;


#include "Elevator.h"
#include "Floor.h"

int Elevator::elevatorID = 0;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = -1;


Elevator::Elevator(const int capacity, const int speed, const Floor& startFloor):ID(elevatorID),capacity(capacity), speed(speed),toFloor(0)
{
  location = startFloor.getLocation();
  direction = IDLE;
  doorOpen = true;
}

bool Elevator::isNearDestination() const
{
  double distance = ((toFloor->getLocation()) - location);
  
  if(distance < 0)
  {
    distance=distance*-1;
  }
  
  if(distance <= speed)
  {
    return true;
  }
  else
  {
    return false;
  }
}


void Elevator::moveToDestinationFloor()
{
  if(hasADestination()==true)
  {
    location = toFloor->getLocation();
  }
}

ostream& operator<<(ostream& out, const Elevator& a)
{
  int count=a.riders.size();
  if(count==0)
  {
    out<<"No Riders"<<endl;
  }
  else if(count==1)
  {
    out<<"1 Rider"<<endl;
  }
  else
  {
    out<<count<<" Riders"<<endl;
  }
  
  out << "Elevator is located at "<< a.getLocation() << " inches from the ground."<<endl;
  
  if(a.isIdle())
  {
    out<<"The Elevator is idle, "<<endl;
  }
  else if(a.isDirectionUp())
  {
    out<<"The Elevator is moving up, "<<endl;
  }
  else if(a.isDirectionDown())
  {
    out<<"The Elevator is moving down, "<<endl;
  }
  
  if(a.isDoorOpen())
  {
    out <<"The Door is open. "<<endl;
  }
  else
  {
    out <<"The Door is closed. "<<endl;
  }
  return out;
}

vector<Rider> Elevator::removeRidersForDestinationFloor()
{
  vector<Rider> leaving;
  
  if(riders.size() !=0)
  {
    vector<Rider> staying;
    
    for(int i=0; i<riders.size();i++)
    {
      if(toFloor==&riders[i].getDestination())
      {
        leaving.push_back(riders[i]);
      }
      else
      {
        staying.push_back(riders[i]);
      }
    }
    riders = staying;
  }
  return leaving;
}

void Elevator:: addRiders(const vector<Rider>& r)
{
  vector<Rider>::const_iterator i;
  for(i=r.begin(); i != r.end(); i++)
  {
    if(riders.size()<capacity)
    {
      riders.push_back(*i);
    }
  }
}

void Elevator::setDestinationBasedOnRiders()
{
  if(!hasRiders()) return;
  int distance =1;
  
  for(int i=0;i<riders.size();i++)
  {
    distance = getLocation()-riders[i].getDestination().getLocation();
    distance=abs(distance);//get absolute value of distnace
    if(getLocation()-riders[i].getDestination().getLocation() < 0 || getLocation()-riders[i].getDestination().getLocation()>distance)
    {
      distance = getLocation()-riders[i].getDestination().getLocation();
    }
    setDestination(&riders[i].getDestination());
  }
}