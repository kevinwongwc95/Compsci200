// Lab 8A Write And Test A Queue Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

class PhoneNumber
{
  friend ostream &operator<<(ostream &, const PhoneNumber &);
  friend istream &operator>>(istream &, PhoneNumber &);
private:
  string areaCode;
  string exchange;
  string line;
};

#endif
