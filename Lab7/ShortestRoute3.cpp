// Lab 7B Using the const Keyword and strings
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

class Route;

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
	friend void outputLeg(ostream&, const Leg&);
	friend void outputRoute(ostream&, const Route&);
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
	friend void outputRoute(ostream&, const Route&);
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
	for(int i=0; i<a.counter+1; i++)
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

void outputLeg(ostream&, const Leg&);
void outputRoute(ostream&, const Route&);

int main()
{
  
  cout << "Lab 7B, Using the const Keyword and strings  b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
	//creates the legs and prints out the info
	Leg a("Walnut Creek", "San Francisco", 25);
  Leg b("San Francisco", "San Jose", 50);
  Leg c("San Jose", "Los Angeles", 400);
  Leg d("Los Angeles", "Las Vegas", 250);
  Leg e("Las Vegas", "Pheonix", 300);
  
  
  //exception testing
  try
  {
    Route(Route(Leg("a", "b", 0)), Leg("c", "d", 0));
  }
  catch (string ex)
  {
    cout << "ERROR DETECTED: " << ex << endl;
  }

  
  //prints legs
	outputLeg(cout, a);
	outputLeg(cout, b);
	outputLeg(cout, c);
	outputLeg(cout, d);
	outputLeg(cout, e);
  
	//create 5 routes
	Route ra(a);
	Route rb(ra, b);
	Route rc(rb, c);
	Route rd(rc, d);
	Route re(rd, e);
  
  { // start local scope
    Route rCopy = ra;
    outputRoute(cout, rCopy);
  } // end local scope
  
	outputRoute(cout, re);
	cout << endl;
  
  //test route comparison function
  if(rb.isGreaterThan(ra))
  {
    cout<<"Leg rb is longer than route ra"<<endl;
  }
  else
  {
    cout<<"Leg rb is shorter than route ra"<<endl;
  }
  
  if(rc.isGreaterThan(rb))
  {
    cout<<"Leg rc is longer than route rb"<<endl;
  }
  else
  {
    cout<<"Leg rc is shorter than route rb"<<endl;
  }
  if(rd.isGreaterThan(rc))
  {
    cout<<"Leg rd is longer than route rc"<<endl;
  }
  else
  {
    cout<<"Leg rd is shorter than route rc"<<endl;
  }
  
}

//output route cities, and total distance
void outputRoute(ostream& out, const Route& route)
{
  out<<route.leg[0]->startLeg;
  
  for (int i=1; i<route.counter; i++)
  {
    out<<" to " <<route.leg[i]->startLeg;
  }
  
  out<<" to " <<route.leg[route.counter-1]->endLeg<< ": "<< route.totaldistance<<" miles "<<endl;
}

void outputLeg(ostream& out, const Leg& journey)
{
  out<<journey.startLeg<<" to "<<journey.endLeg<<": "<<journey.distance<<" miles"<<endl;
}

