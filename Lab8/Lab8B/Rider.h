// Lab Lab 8b Using Operator Overloading
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Rider_h
#define Rider_h

class Floor;

class Rider
{
private:
  const int idnumber; //id number
  const Floor* const destination; //destination
  static int riderCount;
  
public:
  //constructor, initialize rider id, increment riderCount
  Rider(const Floor& x):destination(&x), idnumber(riderCount)
  {
    ++riderCount;
  }
  bool operator<(Rider a) const; //compare two riders if one is greater than other
  bool operator==(Rider a) const;//compare two riders if they are equal by id number
  const Floor& getDestination() const
  {
    return *destination; 
  }
  
  Rider& operator= (Rider &);
  
};

#endif
