// LAB 9a
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Array_h
#define Array_h

#include <iostream>
using std::ostream;
using std::istream;

class Array
{
  friend ostream &operator<<( ostream &, const Array &);
  friend istream &operator>>(istream &, Array &);
public:
  Array(int=10);
  Array(const Array &);
  ~Array();
  int getSize() const;
  
  const Array &operator=(const Array &);
  bool operator==(const Array &) const;
  
  bool operator !=(const Array &right) const
  {
    return!(*this==right);
  }
  
  int &operator[](int);
  
  int operator [] (int) const;
  
private:
  int size;
  int *ptr;
};

#endif
