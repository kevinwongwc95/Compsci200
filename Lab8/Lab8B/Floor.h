// Lab Lab 8b Using Operator Overloading
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Floor_h
#define Floor_h

class Floor
{
public:
  Floor(const int height): location(height) // floor constructor
  {
  }
  int getLocation() const //getter function that returns int height of floor
  {
    return location;
  }
private:
  const int location; //height of the floor, in inches above the ground
};

#endif
