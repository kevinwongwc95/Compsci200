//Lab 10b Using vectors
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "Rider.h"

int Rider::riderCount=0;

class Floor;

//operator definition, compares two riders by ID
bool Rider::operator<(Rider a) const
{
  bool result = false;
  if (idnumber < a.idnumber)
  {
    result = true;
  }
  return result;
}

//operator definition, compares two riders by ID if they are equal
bool Rider::operator==(Rider a) const
{
  bool result = true;
  if (idnumber != a.idnumber)
  {
    result = false;
  }
  return result;
}

const Rider& Rider::operator=(const Rider &r)
{
  if (&r !=this)
  {
    const_cast<int&>(idnumber) = r.idnumber;
    const_cast<const Floor*&>(destination) = r.destination;
  }
  return *this;
}