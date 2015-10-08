// Lab 1b GeometryHomework
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;


#include <cstdlib>



#include <fstream>
using std::ifstream;



const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";

int main()
{

  cout << "Lab 1b, GeometryHomework b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // create a file-reading object
  ifstream fin;
  fin.open("geo.txt"); // open a file
  if (!fin.good())
    return 1; // exit if file not found
  // read each line of the file
  while (!fin.eof())
  {
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);

    // parse the line into blank-delimited tokens
    int n = 0; // a for-loop index

    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      }
    }


    if(token[0]==0)
    {
      continue;
    }
    if (token[1]==0)
    {
      token[1]="0";
    }
    if (token[2]==0)
    {
      token[2]="0";
    }
    if (token[3]==0)
    {
      token[3]="0";
    }


    if(strcmp(token[0],"SQUARE")==0)
    {
      double side, perimeter, area;
      side=atof(token[1]);
      perimeter=side*4;
      area=side*side;

      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6);

      cout<<"SQUARE Side="<<side;

      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2);

      cout<<" Perimeter="<<perimeter<<" Area="<<area<<endl;



    }

    else if(strcmp(token[0],"RECTANGLE")==0)
    {
      double length, width, area, perimeter;
      length=atof(token[1]);
      width=atof(token[2]);
      area=width*length;
      perimeter=(2*length)+(2*width);

      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6);

      cout<<"Rectangle length="<<length<<" width="<<width;

      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2);

      cout<<" area="<<area<<" perimeter="<<perimeter<<endl;


    }

    else if (strcmp(token[0],"CIRCLE")==0)
      {
        double radius, circumference, area;
        radius=atof(token[1]);
        circumference=2*3.1415*radius;
        area=3.1415*radius*radius;

        cout.unsetf(ios::fixed|ios::showpoint);
        cout << setprecision(6);

        cout<<"Circle Radius="<<radius;

        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2);

        cout<<" Area="<<area<<" Circumference="<<circumference<<endl;
      }

    else if (strcmp(token[0],"CUBE")==0)
    {
      double side,surface, volume;
      side=atof(token[1]);
      surface=side*side*6;
      volume=side*side*side;

      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6);

      cout<<"Cube Side="<<side;

      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2);

      cout<<" Surface Area="<<surface<<" Volume="<<volume<<endl;
    }

    else if(strcmp(token[0],"PRISM")==0)
    {
      double length, width, height, surface, volume;
      length=atof(token[1]);
      width=atof(token[2]);
      height=atof(token[3]);
      surface=(2*length*width)+(2*length*height)+(2*width*height);
      volume=length*width*height;

      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6);

      cout<<"Prism Length="<<length<<" Width="<<width<<" Height="<<height;

      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2);

      cout<<" Surface Area="<<surface<<" Volume="<<volume<<endl;

    }

    else if(strcmp(token[0],"CYLINDER")==0)
    {
      double radius, height, surface, volume;
      radius=atof(token[1]);
      height=atof(token[2]);
      surface=((2*3.1415*radius*height)+(2*3.1415*radius*radius));
      volume=3.1415*radius*radius*height;

      cout.unsetf(ios::fixed|ios::showpoint);
      cout << setprecision(6);

      cout<<"Cylinder radius="<<radius<<" height="<<height;

      cout.setf(ios::fixed|ios::showpoint);
      cout << setprecision(2);

      cout<<" surface area="<<surface<<" volume="<<volume<<endl;
    }

    else
    {
      cout<<token[0]<<" Invalid Object"<<endl;
    }



  }

}

