// Term Project Solving The Shortest-Route Problem
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Route;
class ShortestRoute;

class Leg
{
private:
	const string startLeg;
	const string endLeg;
	const int distance;
public:
	Leg(const string first,const string second, const double miles):startLeg(first),endLeg(second), distance(miles)
  {};
	friend class Route;
  friend class ShortestRoute;
  friend ostream& operator<<(ostream&, const Route&);
  friend ostream& operator<<(ostream&, const Leg&);
  void operator=(const Leg&){};
};

class Route
{
private:
  const int counter;
	const Leg** const leg;
	const double totaldistance;
public:
  bool isGreaterThan(const Route&) const;
	Route(const Leg&);
	Route(const Route&, const Leg&);
	Route(const Route&);
	~Route()//destructor
  {
    delete[] leg;
  }
  friend class ShortestRoute;
  friend ostream& operator<<(ostream&, const Route&);
  void operator=(const Leg&){}
  
};

class ShortestRoute
{
public:
  static vector<Leg> legs;
  static const Route getAnyRoute(const string, const string);
  static const Route getShortestRoute(const string, const string);
};

Route::Route(const Leg& a):counter(1),leg(new const Leg*[1]), totaldistance(a.distance)
//constructor that take in a leg to create a route
{
  leg[0]=&a;
}

//constructor that adds a leg to an existing route
Route::Route(const Route& routeA, const Leg& legA):counter(routeA.counter+1),leg(new const Leg*[routeA.counter+1]),totaldistance(routeA.totaldistance+legA.distance)
{
	for(int i = 0; i< counter-1; i++)
  {
    leg[i] = routeA.leg[i];
  }
	leg[routeA.counter]=&legA;
  
  //exception handeling
  if(((routeA.leg[counter-2]->endLeg).compare(legA.startLeg))!=0)
  {
    string ex="End leg of route doesn't match start city of new leg";
    delete[] leg;
    throw ex;
  }
}

Route::Route(const Route& a):counter(a.counter),leg(new const Leg*[counter]), totaldistance(a.totaldistance) //copy constructor
{
	for(int i=0; i<a.counter; i++)
  {
    leg[i]=a.leg[i];
  }
}

//compare function
bool Route:: isGreaterThan(const Route& a) const
{
  bool choice=false;
  if((this->totaldistance)>(a.totaldistance))
  {
    choice=true;
    return choice;
  }
  return choice;
}

vector<Leg> ShortestRoute::legs;

void outputLeg(ostream&, const Leg&);
void outputRoute(ostream&, const Route&);

int main()
{
  //output student info
  cout << "Term Project Solving The Shortest-Route Problem  b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  //Add Legs
  ShortestRoute::legs.push_back(Leg("San Francisco","Butte",995));
  ShortestRoute::legs.push_back(Leg("San Francisco","Carson City",250));
  ShortestRoute::legs.push_back(Leg("San Francisco","Las Vegas",570));
  ShortestRoute::legs.push_back(Leg("Butte","Omaha",1150));
  ShortestRoute::legs.push_back(Leg("Carson City","Salt Lake City",550));
  
  ShortestRoute::legs.push_back(Leg("Las Vegas","Albuquerque",500));
  ShortestRoute::legs.push_back(Leg("Las Vegas","Phoenix",302));
  ShortestRoute::legs.push_back(Leg("Omaha","Chicago",395));
  ShortestRoute::legs.push_back(Leg("Salt Lake City","Omaha",906));
  ShortestRoute::legs.push_back(Leg("Salt Lake City","Chicago",1400));
  ShortestRoute::legs.push_back(Leg("Salt Lake City","Denver",480));
  
  ShortestRoute::legs.push_back(Leg("Denver","Independance",600));
  ShortestRoute::legs.push_back(Leg("Denver","Oklahoma",640));
  ShortestRoute::legs.push_back(Leg("Denver","Albuquerque",470));
  
  ShortestRoute::legs.push_back(Leg("Phoenix","Albuquerque",467));
  ShortestRoute::legs.push_back(Leg("Phoenix","Houston",980));
  ShortestRoute::legs.push_back(Leg("Albuquerque","Houston",840));
  ShortestRoute::legs.push_back(Leg("Oklahoma","Independance",332));
  ShortestRoute::legs.push_back(Leg("Independance","Chicago",530));
  ShortestRoute::legs.push_back(Leg("Independance","Madison",480));
  
  ShortestRoute::legs.push_back(Leg("Chicago","Madison",172));
  ShortestRoute::legs.push_back(Leg("Chicago","Detroit",250));
  ShortestRoute::legs.push_back(Leg("Oklahoma","Birmingham",700));
  ShortestRoute::legs.push_back(Leg("Oklahoma","New Orleans",750));
  ShortestRoute::legs.push_back(Leg("Oklahoma","Houston",430));
  
  ShortestRoute::legs.push_back(Leg("Houston","Baton Rouge",329));
  ShortestRoute::legs.push_back(Leg("Baton Rouge","New Orleans",74));
  ShortestRoute::legs.push_back(Leg("New Orleans","Birmingham",343));
  ShortestRoute::legs.push_back(Leg("Detroit","Buffalo",770));
  ShortestRoute::legs.push_back(Leg("Detroit","Madison",272));
  ShortestRoute::legs.push_back(Leg("Madison","Buffalo",500));
  
  ShortestRoute::legs.push_back(Leg("Madison","Lexington",120));
  ShortestRoute::legs.push_back(Leg("Madison","Birmingham",407));
  ShortestRoute::legs.push_back(Leg("Birmingham","Lexington",405));
  ShortestRoute::legs.push_back(Leg("Birmingham","Miami",809));
  
  ShortestRoute::legs.push_back(Leg("Lexington","Miami",1005));
  ShortestRoute::legs.push_back(Leg("Lexington","Raleigh",410));
  ShortestRoute::legs.push_back(Leg("Lexington","Washington DC",520));
  ShortestRoute::legs.push_back(Leg("Miami","Raleigh",810));
  ShortestRoute::legs.push_back(Leg("Buffalo","Washington DC",400));
  ShortestRoute::legs.push_back(Leg("Buffalo","New York",340));
  
  ShortestRoute::legs.push_back(Leg("Washington DC","New York",201));
  ShortestRoute::legs.push_back(Leg("Raleigh","New York",490));
  
  
  ShortestRoute::legs.push_back(Leg("San Francisco","New York",21000));//SuperHighway
  
  
  // For any route
  try
  {
    cout << "Any route is: " << endl;
    cout << ShortestRoute::getAnyRoute("San Francisco", "New York") << endl;
  }
  catch (const string e)
  {
    cout << "ERROR: " << e << endl;
  }
  cout << endl;
  
  // For shortest route
  try
  {
    cout << "Shortest route is: " << endl;
    cout << ShortestRoute::getShortestRoute("San Francisco", "New York") << endl;
  }
  catch (const string e)
  {
    cout << "ERROR: " << e << endl;
  }
  cout << endl;
}

//output route cities, and total distance
ostream& operator <<(ostream& out, const Route& route)
{
  out<<route.leg[0]->startLeg;
  
  for (int i=1; i<route.counter; i++)
  {
    out<<" to " <<route.leg[i]->startLeg;
  }
  
  out<<" to " <<route.leg[route.counter-1]->endLeg<< ": "<< route.totaldistance<<" miles "<<endl;
  
  return out;
}

ostream& operator<<(ostream& out, const Leg& journey)
{
  out<<journey.startLeg<<" to "<<journey.endLeg<<": "<<journey.distance<<" miles"<<endl;
  return out;
}


const Route ShortestRoute::getShortestRoute(const string start, const string end)
{
  vector<Route> routeGroup;
  for(int i = 0; i < legs.size(); i++)
  {
    //if they are the same, add into allRoutes
    if ((legs[i].startLeg == start) && (legs[i].endLeg == end))
    {
      routeGroup.push_back(Route(legs[i]));
    }
    else if(legs[i].endLeg == end)
    {
      routeGroup.push_back(Route(getShortestRoute(start, legs[i].startLeg), legs[i]));
    }
  }
  
  if (routeGroup.size() == 0)
  {
    throw "No Valid Route";
  }
  
  int j = 0;
  for(int i = 0; i < routeGroup.size(); i++)
  {
    if((routeGroup[j].isGreaterThan(routeGroup[i])) == true)
    {
      j = i;
    }
  }
  
  return routeGroup[j];
}

const Route ShortestRoute::getAnyRoute(const string start, const string end)
{
  for (int i = 0; i < legs.size(); i++)
  {
    if ((legs[i].startLeg == start) && (legs[i].endLeg == end))
    {
      return Route(legs[i]);
    }
    else if(legs[i].endLeg == end)
    {
      return Route(getAnyRoute(start, legs[i].startLeg), legs[i]);
    }
  }
  throw "Error" ;
}
