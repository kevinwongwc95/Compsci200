// Lab 7A
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;


int main()
{
  cout << "Lab 7A b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  string string1( "noon is 12pm; midnight is not." );
  int location;

  cout<<"Original string:\n"<<string1
  <<"\n\n(find) \"is\" was found at: "<<string1.find("is")
  <<"\n(rfind)\"is\" was found at: "<<string1.rfind("is");

  location=string1.find_first_of("misop");
  cout<<"\n\n(find_first_of) found '"<<string1[location]
  <<"'from the group\"misop\" at: "<< location;

  location= string1.find_last_of("misop");
  cout<<"\n\n(find_last_of) found'"<<string1[location]<<"'from the group\"misop\" at: "<<location;

  location=string1.find_first_not_of("noi spm");
  cout<<"\n\n(find_first_not_of) '"<<string1[location]
  <<"' is not contained in \"noi spm\" and ws found at: "<<location;

  location=string1.find_first_not_of("12 noi spm");
  cout<<"\n\n(find_first_not_of) '"<<string1[location]<<"' is not contained in \"12noi spm\" and was "<<"found at: "<<location<<endl;

  //test of the string 2
  cout<<endl;
  string string2( "Hello my name is Kevin Wong." );

  cout<<"Original string:\n"<<string2
  <<"\n\n(find) \"is\" was found at: "<<string2.find("is")
  <<"\n(rfind)\"is\" was found at: "<<string2.rfind("is");

  //return 2
  location=string2.find_first_of("maeko");
  cout<<"\n\n(find_first_of) found '"<<string2[location]
  <<"'from the group\"misop\" at: "<< location;

  //return 24
  location= string2.find_last_of("misop");
  cout<<"\n\n(find_last_of) found'"<<string2[location]<<"'from the group\"misop\" at: "<<location;

  //return 1
  location=string2.find_first_not_of("noi spm");
  cout<<"\n\n(find_first_not_of) '"<<string2[location]
  <<"' is not contained in \"noi spm\" and ws found at: "<<location;

  //return 1
  location=string2.find_first_not_of("12 noi spm");
  cout<<"\n\n(find_first_not_of) '"<<string2[location]<<"' is not contained in \"12noi spm\" and was "<<"found at: "<<location<<endl;

}
