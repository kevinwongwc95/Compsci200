//Lab Lab 10a Using Inline Functions And Constants
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::ostream;

class Date
{
  friend ostream &operator <<(ostream &, const Date&);
public:
  Date(int m=1, int d=1, int y=1900);
  void setDate(int, int, int);
  Date& operator++();
  Date operator++(int);
  const Date &operator+=(int);
  static bool leapYear(int);
  bool endOfMonth(int) const;
private:
  int month;
  int day;
  int year;
  
  static const int days[];
  void helpIncrement();
};

#endif
