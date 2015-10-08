// Lab 6A
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Time_h
#define Time_h

class Time
{
public:
  Time( int=0, int=0, int=0);
  Time &setTime(int, int, int);
  Time &setHour (int);
  Time &setMinute (int);
  Time &setSecond(int);
  
  int getHour() const;
  int getMinute() const;
  int getSecond() const;
  
  void printUniversal () const;
  void printStandard() const;
  
private:
  int hour;
  int minute;
  int second;
};

#endif
