//Lab 15 Using The STL
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "Building.h"
#include "Rider.h"
#include "Elevator.h"
#include "Floor.h"

#include <cstdlib>

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

Building::Building() : Time(0)
{
  Floor *basement= new Floor(-100, "Basement");
  floors.push_back(basement);
  Floor *ground=new Floor(0, "Ground Floor");
  floors.push_back(ground);
  Floor *first=new Floor(100, "First Floor");
  floors.push_back(first);
  Floor *second=new Floor(200, "Second Floor");
  floors.push_back(second);
  Floor *third=new Floor(300, "Third Floor");
  floors.push_back(third);
  Floor *fourth=new Floor(400, "Fourth Floor");
  floors.push_back(fourth);

  Elevator *e1=new Elevator (5,5,*floors[0]);
  elevators.push_back(e1);
  Elevator *e2=new Elevator (5,5,*floors[1]);
}

Building& Building::step(int max)
{
  for(int i = 0; i < max; i++)
  {
    int topFloor = getFloorCount();
    int firstFloor; // starting floor int
    int lastFloor; // ending floor int
    getDifferentInts(topFloor, firstFloor, lastFloor); // call getDifferentInts creates 2 random ints that are not equal to one another
    floors[firstFloor]->addNewRider(Rider(*floors[lastFloor])); // rider loop
  }
  // ELEVATOR ACTIONS [3]
  for(int i = 0; i < getElevatorCount(); i++) // tell each elevator to perform an action [3]
  {
    if(getElevator(i).isDoorOpen() == false)  // if elevator door is closed
    {
      if(getElevator(i).isNearDestination() == false)  // if not near enough to destination to reach it in this time step, continue moving [3]
      {
        if(getElevator(i).isDirectionUp() == true)  // if elevator direction is up, move up [3]
        {
          elevators[i]->moveUp();
        }
        else  // otherwise, move down [3]
        {
          elevators[i]->moveDown();
        }
      }

      else  // otherwise it's near enough to destination to reach it in this time step... [4]
      {
        elevators[i]->moveToDestinationFloor(); // tell elevator to move to its destination floor [4]
        elevators[i]->openDoor(); // tell elevator to open its door [4]
        elevators[i]->removeRidersForDestinationFloor(); // tell elevator to remove riders for its destination floor -- ignore returned vector of removed riders [4]
        Floor* temp;// get a non-const pointer to the elevator's destination floor (using const_cast) [5]
        const_cast<const Floor*&>(temp) = &getElevator(i).getDestination();

        if(getElevator(i).getRiderCount() == 0)  // if elevator is empty
        {
          //choose a direction based on longest-waiting rider (the one with the smallest ID) on the floor: [5]
          if(temp->isPreferredDirectionUp() == true) // if the floor's chosen direction is up [5]
            elevators[i]->setDirectionUp(); // tell elevator to set its direction to up [5]
          else // otherwise [5]
            elevators[i]->setDirectionDown(); // tell elevator to set its direction to down [5]
        }

        if(getElevator(i).getAvailableSpace() > 0 && elevators[i]->isDoorOpen() == true)  // if there is space in the elevator after letting off riders
        {
          // board new ones [6]
          if(getElevator(i).isDirectionUp() == true)  // if elevator direction is up, board up-riders (if any)... [6]
          {
            elevators[i]->addRiders(temp->removeUpRiders(elevators[i]->getAvailableSpace()));
          }
          else  // otherwise, board down-riders (if any) [6]
          {
            elevators[i]->addRiders(temp->removeDownRiders(elevators[i]->getAvailableSpace()));
          }
        }
        // reassess elevator destination based on its riders [8]
        elevators[i]->setDestinationBasedOnRiders();
      }
    }
    // otherwise (then it already let off riders, or is in its initial state) [7]
    else
    {
      if(getElevator(i).hasRiders() == true)  // if elevator has any riders
      {
        elevators[i]->closeDoor(); // tell elevator to close its door [7]
      }
      else
      {
        elevators[i]->setIdle();
      }
    }

  }

  // FLOOR ACTIONS [2]
  // check each floor (for waiting riders) [2]
  for(int i = 0; i < getFloorCount(); i++)
  {
    if(getFloor(i).hasRidersWaiting() == false)  // if there are no riders waiting on this floor, continue with next floor [2]
    {
      continue;
    }
    for(int j = 0; j < getElevatorCount(); j++)
    {

      int Location = elevators[j]->getLocation() - floors[i]->getLocation(); // get elevator's relative location

      if(getElevator(j).isIdle() == true)  // look at each elevator to see if it needs to be sent here [2]
      {

        if(Location >= 0)  // elevator is above if positive
        {
          elevators[j]->setDirectionDown(); // set elevator direction to down [2]
          elevators[j]->setDestination(floors[i]);// set elevator's destination to this floor [2]
          elevators[j]->closeDoor(); // tell elevator to close its door [2]
        }

        else
        {
          elevators[j]->setDirectionUp();// set elevator direction to up [2]
          elevators[j]->setDestination(floors[i]); // set elevator's destination to this floor [2]
          elevators[j]->closeDoor(); // tell elevator to close its door [2]
        }
      }

      // else if there are riders on this floor waiting to go up, and the elevator is going up... [10]
      else if(getFloor(i).hasUpRiders() == true && getElevator(j).isDirectionUp() == true)
      {
        // get distance from elevator's destination floor to this floor (positive if elevator destination is above this floor) [10]
        double DistancetoFloor = getElevator(j).getDestination().getLocation() - getFloor(i).getLocation();
        if (DistancetoFloor > 0 && Location < 0)  // if elevator is below floor and elevator destination is above this floor [10]
        {
          elevators[j]->setDestination(&(getFloor(i))); // set elevator's destination to this floor [10]
        }
      }

      else if(getFloor(i).hasUpRiders() == true && getElevator(j).isDirectionUp() == true)
      {
        // get distance from elevator's destination floor to this floor (negative if elevator destination is below this floor) [10]
        double difference = getElevator(j).getDestination().getLocation() - getFloor(i).getLocation();
        if (difference < 0 && Location > 0)  // if elevator is above floor and elevator destination is below this floor [10]
        {
          elevators[j]->setDestination(&(getFloor(i))); // set elevator's destination to this floor [10]
        }
      }

    }
  }

  Time++;
  return *this;
}

//get random numbers
void Building::getDifferentInts(int max, int&x, int& y)
{
  do
  {
    x = rand() % max;
    y = rand() % max;
  }
  while(x==y);
}

ostream& operator<<(ostream& out, const Building& x)
{
  out<< "Time in seconds is: " << x.Time << endl;

  for(int i = 0; i < x.elevators.size(); i++)
  {
    out <<"Elevator # " << i+1 << endl << *x.elevators[i] <<endl;
  }
  for(int i = 0; i< x.floors.size(); i++)
  {
    if(x.getFloor(i).hasRidersWaiting())
      out<< *x.floors[i];
  }
  return out;
}

//Building Destructor
Building::~Building()
{
  for(int i=0; i<getFloorCount(); i++)
    delete floors[i];
  for(int i=0; i<getElevatorCount(); i++)
    delete elevators[i];
}
