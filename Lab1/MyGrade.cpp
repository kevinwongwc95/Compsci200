// Lab 1a Mygrade
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>



int main()
{

  int total;
  int gradeCounter;
  int grade;
  int average;

  string buf;

  total=0;
  gradeCounter=1;

  // print student and program information
  cout << "Lab 1a, My Grade b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  while(gradeCounter<=10)
  {
    cout<<"Enter grade: ";
    cin >> buf;
    grade = atoi(buf.c_str());
    total=total+grade;
    gradeCounter=gradeCounter+1;
  }

  average=total/10;

  cout<<"\nTotal of all 10 grades is " <<total<<endl;
  cout<<"Class average is "<<average<<endl;

}
