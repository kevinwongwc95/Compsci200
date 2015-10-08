// Lab 11 Using Inheritance
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <iomanip>
using std::setprecision;

#include <cstdlib>

#include <cstring>

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";

ostream& reset(ostream& out);
ostream& set(ostream& out);

//class definitions
class Square
{
protected:
  const double side;
  
public:
  Square(const char* const token[]):side(token[1]==0?:atof(token[1]))
  {
  }
  void output(ostream& out) const;
  
};

class Rectangle
{
public:
  Rectangle(const char* const token[]):length(token[1]==0?:atof(token[1])),width(token[2]==0?:atof(token[2]))
  {
  }
  void output(ostream& out) const;
  
protected:
  const double length, width;
};

class Circle
{
public:
  Circle(const char* const token[]):radius(token[1]==0?:atof(token[1]))
  {
  }
  void output(ostream& out) const;
  
protected:
  const double radius;
};

class Cube:public Square
{
public:
  Cube(const char* const token[]):Square(token)
  {
  }
  void output(ostream& out) const;
};

class Prism:public Rectangle
{
  const double height;
  
public:
  Prism(const char* const token[]):Rectangle(token), height(token[3]==0?0:atof(token[3]))
  {
  }
  void output(ostream& out) const;
  
};

class Cylinder:public Circle
{
  const double height;
  
public:
  
  Cylinder(const char* const token[]):Circle(token),height(token[2]==0?0:atof(token[2]))
  {
  }
  void output(ostream& out) const;
  
};

//class function definitions*******************************

void Square::output(ostream& out) const
{
  double perimeter, area, side;
  side=this->side;
  perimeter=4*side;
  area=side*side;
  
  cout<<reset;
  
  cout<<"SQUARE Side="<<side;
  
  cout<<set;
  
  cout<<" Perimeter="<<perimeter<<" Area="<<area<<endl;
}

void Rectangle:: output(ostream& out) const
{
  double length, width, area, perimeter;
  length=this->length;
  width=this->width;
  area=length*width;
  perimeter=(2*length)+(2*width);
  
  cout<<reset;
  
  cout<<"Rectangle length="<<length<<" width="<<width;
  
  cout<<set;
  
  cout<<" area="<<area<<" perimeter="<<perimeter<<endl;
}

void Circle::output(ostream& out) const
{
  double radius, circumference, area;
  radius=this->radius;
  circumference=2*3.1415*radius;
  area=3.1415*radius*radius;
  
  cout<<reset;
  
  cout<<"Circle Radius="<<radius;
  
  cout<<set;
  
  cout<<" Area="<<area<<" Circumference="<<circumference<<endl;
}

void Cube::output(ostream& out) const
{
  double side, volume, surfacearea;
  side=this->side;
  surfacearea=6*side*side;
  volume=side*side*side;
  
  cout<<reset;
  
  cout<<"Cube Side="<<side;
  
  cout<<set;
  
  cout<<" Surface Area="<<surfacearea<<" Volume="<<volume<<endl;
}

void Prism::output(ostream& out) const
{
  double length, width, height, surfacearea, volume;
  length=this->length;
  width=this->width;
  height=this->height;
  surfacearea=(2*width*height)+(2*width*length)+(2*length*height);
  volume=(height*length*width);
  
  cout<<reset;
  
  cout<<"Prism Length="<<length<<" Width="<<width<<" Height="<<height;
  
  cout<<set;
  
  cout<<" Surface Area="<<surfacearea<<" Volume="<<volume<<endl;
}

void Cylinder::output(ostream& out) const
{
  double height, radius, surfacearea, volume;
  height=this->height;
  radius=this->radius;
  volume=(3.1415*radius*radius*height);
  surfacearea= (2*3.1415*radius*height)+(2*3.1415*radius*radius);
  
  cout<<reset;
  
  cout<<"Cylinder radius="<<radius<<" height="<<height;
  
  cout<<set;
  
  cout<<" surface area="<<surfacearea<<" volume="<<volume<<endl;
}

//int main****************************************************

int main()
{
  vector<const void*> shapes;
  vector <int> shapeID;
  
  cout << "Lab 11 Using Inheritance b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // create a file-reading object
  ifstream fin;
  fin.open("geo.txt"); // open a file
  if (!fin.good())
  {
    return 1; // exit if file not found
  }
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
    
    //if a square create pointer to square and add to array
    if(strcmp(token[0],"SQUARE")==0)
    {
      const Square * const s=new Square{token};
      shapes.push_back(s);
      shapeID.push_back(1);
    }
    
    //if a rectangle create pointer to square and add to array
    
    else if(strcmp(token[0],"RECTANGLE")==0)
    {
      const Rectangle* const r=new Rectangle{token};
      shapes.push_back(r);
      shapeID.push_back(2);
    }
    
    //if a circle create pointer to square and add to array
    else if (strcmp(token[0],"CIRCLE")==0)
    {
      const Circle* const c=new Circle{token};
      shapes.push_back(c);
      shapeID.push_back(3);
    }
    
    //if a cube create pointer to square and add to array
    else if (strcmp(token[0],"CUBE")==0)
    {
      const Cube* const cub=new Cube{token};
      shapes.push_back(cub);
      shapeID.push_back(4);
    }
    
    //if a prism create pointer to square and add to array
    else if(strcmp(token[0],"PRISM")==0)
    {
      const Prism* const p=new Prism{token};
      shapes.push_back(p);
      shapeID.push_back(5);
    }
    
    //if a cylinder create pointer to square and add to array
    else if(strcmp(token[0],"CYLINDER")==0)
    {
      const Cylinder* const cy=new Cylinder{token};
      shapes.push_back(cy);
      shapeID.push_back(6);
    }
    
    //print invalid object if not recognized
    else
    {
      cout<<"Invalid Object: "<<token[0]<<endl;
    }
  }
  //close file
  fin.close();
  
  for(int x=0; x<shapes.size(); x++)
  {
    if(shapeID[x]==1)
    {
      ((Square*)shapes[x])->output(cout);
    }
    else if(shapeID[x]==2)
    {
      ((Rectangle*)shapes[x])->output(cout);
    }
    else if(shapeID[x]==3)
    {
      ((Circle*)shapes[x])->output(cout);
    }
    else if(shapeID[x]==4)
    {
      ((Cube*)shapes[x])->output(cout);
    }
    else if(shapeID[x]==5)
    {
      ((Prism*)shapes[x])->output(cout);
    }
    else if(shapeID[x]==6)
    {
      ((Cylinder*)shapes[x])->output(cout);
    }
  }
  
  for(int x=0; x<shapes.size(); x++)
  {
    if(shapeID[x]==1)
    {
      delete ((Square*)shapes[x]);
    }
    else if(shapeID[x]==2)
    {
      delete ((Rectangle*)shapes[x]);
    }
    else if(shapeID[x]==3)
    {
      delete ((Circle*)shapes[x]);
    }
    else if(shapeID[x]==4)
    {
      delete ((Cube*)shapes[x]);
    }
    else if(shapeID[x]==5)
    {
      delete ((Prism*)shapes[x]);
    }
    else if(shapeID[x]==6)
    {
      delete ((Cylinder*)shapes[x]);
    }
  }
}

ostream& reset(ostream& out) // requires iostream, using ostream
{
  out.unsetf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(6); // requires iostream and iomanip, using setprecision
  return out;
}

ostream& set(ostream& out) // requires iostream, using ostream
{
  out.setf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(2); // requires iostream and iomanip, using setprecision
  return out;
}