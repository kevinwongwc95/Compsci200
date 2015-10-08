// Lab 2A
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

class Time
{
public:
  Time();
  void setTime (int, int, int);
  void printUniveral();
  void printStandard();
  
private:
  int hour;
  int minute;
  int second;
};

Time::Time()
{
  hour=minute=second=0;
}

void Time::setTime(int h, int m, int s)
{
  hour=(h>=0 && h<24)? h:0;
  minute=(m>=0 && m<60)? m:0;
  second=(s>=0 && s<60)? s :0;
}

void Time::printUniveral()
{
  cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<minute<<":"<<setw(2)<<second;
}

void Time::printStandard()
{
  cout<<((hour==0 || hour==12) ? 12 : hour %12)<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second<<(hour<12 ? "AM" : "PM");
}

int main()
{
  Time t;
  
  cout << "Lab 2A \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  
  cout<<"The initial universal time is ";
  t.printUniveral();
  cout<<"\nThe initial standard time is ";
  t.printStandard();
  
  t.setTime(13,27,6);
  
  cout<<"\n\nUniversal time after setTime is ";
  t.printUniveral();
  cout<< "\nStandard time after setTime is ";
  t.printStandard();
  
  t.setTime(99,99,99);
  
  cout<<"\n\nAfter attempting invalid settings: "<<"\nUniversl time: ";
  t.printUniveral();
  cout<<"\nStandard time: ";
  t.printStandard();
  cout<<endl;
  
}





