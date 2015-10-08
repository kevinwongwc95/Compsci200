// Lab 3B Writing With Data
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

#include <cstring>

#include <fstream>
using std::ifstream;

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";

class Square
{
public:
  Square(const char* token[])
  {
    this->side=atof(token[1]);
  }

  void output() const;
  
private:
  double side;
};

class Rectangle
{
public:
  Rectangle(const char* token[]);

  void output() const;
  
private:
  double length, width;
};

class Circle
{
public:
  Circle(const char* token[]);
  void output() const;
  
private:
  double radius;
};

class Cube
{
public:
  Cube(const char* token[])
  {
    this->side=atof(token[1]);
  }

  void output() const;

private:
  double side;
};

class Prism
{
public:
  Prism(const char* token[]);
  void output() const;
  
private:
  double length, width, height;
};

class Cylinder
{
public:
  Cylinder(const char* token[]);
  void output() const;

private:
  double radius, height;
};

void Square::output() const
{
  double perimeter, area, side;
  side=this->side;
  perimeter=4*side;
  area=side*side;
  
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  
  cout<<"SQUARE Side="<<side;
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  
  cout<<" Perimeter="<<perimeter<<" Area="<<area<<endl;
}

Rectangle::Rectangle(const char* token[])
{
  this->length=atof(token[1]);
  this->width=atof(token[2]);
}


void Rectangle:: output() const
{
  double length, width, area, perimeter;
  length=this->length;
  width=this->width;
  area=length*width;
  perimeter=(2*length)+(2*width);
  
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  
  cout<<"Rectangle length="<<length<<" width="<<width;
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  
  cout<<" area="<<area<<" perimeter="<<perimeter<<endl;
}

Circle::Circle(const char* token[])
{
  this->radius=atof(token[1]);
}

void Circle::output() const
{
  double radius, circumference, area;
  radius=this->radius;
  circumference=2*3.14*radius;
  area=3.14*radius*radius;
  
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  
  cout<<"Circle Radius="<<radius;
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  
  cout<<" Area="<<area<<" Circumference="<<circumference<<endl;
}

void Cube::output() const
{
  double side, volume, surfacearea;
  side=this->side;
  surfacearea=6*side*side;
  volume=side*side*side;
  
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  
  cout<<"Cube Side="<<side;
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  
  cout<<" Surface Area="<<surfacearea<<" Volume="<<volume<<endl;
}

Prism::Prism(const char* token[])
{
  this->length=atof(token[1]);
  this->width=atof(token[2]);
  this->height=atof(token[3]);
}

void Prism::output() const
{
  double length, width, height, surfacearea, volume;
  length=this->length;
  width=this->width;
  height=this->height;
  surfacearea=(2*width*height)+(2*width*length)+(2*length*height);
  volume=(height*length*width);
  
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  
  cout<<"Prism Length="<<length<<" Width="<<width<<" Height="<<height;
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  
  cout<<" Surface Area="<<surfacearea<<" Volume="<<volume<<endl;
}

Cylinder::Cylinder(const char* token[])
{
  this->radius=atof(token[1]);
  this->height=atof(token[2]);
}


void Cylinder::output() const
{
  double height, radius, surfacearea, volume;
  height=this->height;
  radius=this->radius;
  volume=(3.14*radius*radius*height);
  surfacearea= (2*3.14*radius*height)+(2*3.14*radius*radius);
  
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);
  
  cout<<"Cylinder radius="<<radius<<" height="<<height;
  
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  
  cout<<" surface area="<<surfacearea<<" volume="<<volume<<endl;
}

int main()
{
  void* shapes[100];
  int shapeID[100];
  int counter=0;

  void outputSquare(Square*);
  void outputRectangle(Rectangle*);
  void outputCircle(Circle*);
  void outputCube(Cube*);
  void outputPrism(Prism*);
  void outputCylinder(Cylinder*);

  cout << "Lab 3b, Writing With Data b\n";
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

    //if a square create pointer to square and add to array
    if(strcmp(token[0],"SQUARE")==0)
    {
      Square* s=new Square{token};
      shapes[counter]=s;
      shapeID[counter]=1;
    }

    //if a rectangle create pointer to square and add to array

    else if(strcmp(token[0],"RECTANGLE")==0)
    {
      Rectangle* r=new Rectangle{token};
      shapes[counter]=r;
      shapeID[counter]=2;
    }

    //if a circle create pointer to square and add to array
    else if (strcmp(token[0],"CIRCLE")==0)
    {
      Circle* c=new Circle{token};
      shapes[counter]=c;
      shapeID[counter]=3;
    }

    //if a cube create pointer to square and add to array
    else if (strcmp(token[0],"CUBE")==0)
    {
      Cube* cub=new Cube{token};
      shapes[counter]=cub;
      shapeID[counter]=4;
    }

    //if a prism create pointer to square and add to array
    else if(strcmp(token[0],"PRISM")==0)
    {
      Prism* p=new Prism{token};
      shapes[counter]=p;
      shapeID[counter]=5;
    }

    //if a cylinder create pointer to square and add to array
    else if(strcmp(token[0],"CYLINDER")==0)
    {
      Cylinder* cy=new Cylinder{token};
      shapes[counter]=cy;
      shapeID[counter]=6;
    }

    //print invalid object if not recognized
    else
    {
      cout<<"Invalid Object: "<<token[0]<<endl;
    }

    counter++;
  }
  //close file
  fin.close();

  //loop that outputs the array of shape objects
  for(int x=0; x<counter; x++)
  {
    if(shapeID[x]==1)
    {
      ((Square*)shapes[x])->output();
    }
    else if(shapeID[x]==2)
    {
      ((Rectangle*)shapes[x])->output();
    }
    else if(shapeID[x]==3)
    {
      ((Circle*)shapes[x])->output();
    }
    else if(shapeID[x]==4)
    {
      ((Cube*)shapes[x])->output();
    }
    else if(shapeID[x]==5)
    {
      ((Prism*)shapes[x])->output();
    }
    else if(shapeID[x]==6)
    {
      ((Cylinder*)shapes[x])->output();
    }
  }

  //deallocate memory loop
  for(int x=0; x<counter; x++)
  {
    if(shapeID[x]==1)
    {
      delete ((Square*)shapes[x]);
    }
    else if(shapeID[x]==2)
    {
      delete((Rectangle*)shapes[x]);
    }
    else if(shapeID[x]==3)
    {
      delete((Circle*)shapes[x]);
    }
    else if(shapeID[x]==4)
    {
      delete((Cube*)shapes[x]);
    }
    else if(shapeID[x]==5)
    {
      delete((Prism*)shapes[x]);
    }
    else if(shapeID[x]==6)
    {
      delete((Cylinder*)shapes[x]);
    }
  }
}


