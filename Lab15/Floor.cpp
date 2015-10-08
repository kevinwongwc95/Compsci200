//Lab 14 More STL vectors
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <iostream>
using std::ostream;
using std::istream;

#include "Elevator.h"
#include "Floor.h"
#include "Rider.h"


bool Floor:: isPreferredDirectionUp() const // based on Rider with smallest ID
{
  if(hasDownRiders()!=true)
  {
    return true;
  }
  if(hasUpRiders()!=true)
  {
    return false;
  }
  if(upRiders[0]<downRiders[0])
  {
    return true;
  }
  return false;
}

void Floor:: addNewRider(const Rider& r) // add to up- or down-vector
{
  if(r.getDestination().getLocation()>this->getLocation())
  {
    upRiders.push_back(r);
  }
  else
  {
    downRiders.push_back(r);
  }
}

vector<Rider> Floor:: removeUpRiders(int maximum) // int is max #of riders...
{
  vector <Rider> remove;
  vector <Rider> stay;
  if(hasUpRiders()==true)
  {
    for(int i=0; i<upRiders.size(); i++)
    {
      if(remove.size()!=maximum)
      {
        remove.push_back(upRiders[i]);
      }
      else
      {
        stay.push_back(upRiders[i]);
      }
    }
  }
  upRiders=stay;
  return remove;
}

vector<Rider> Floor:: removeDownRiders(int maximum) //...to move onto elevator
{
  vector <Rider> remove;
  vector <Rider> stay;
  if(hasDownRiders()==true)
  {
    for(int i=0; i<downRiders.size(); i++)
    {
      if(remove.size()!=maximum)
      {
        remove.push_back(downRiders[i]);
      }
      else
      {
        stay.push_back(downRiders[i]);
      }
    }
  }
  downRiders=stay;
  return remove;
}

ostream& operator<<(ostream& out, const Floor& x)
{
  out<<"Floor: "<<x.NAME<<" # of UpRiders: "<<x.upRiders.size()<<" # of DwnRiders: "<<x.downRiders.size()<<" Loc: "<<x.getLocation()<<endl;
  
  return out;
}
