// Lab 2b Encapsulating Data
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;




#include <cstring>


#include <fstream>
using std::ifstream;



const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";

struct Square
{
  double side;
};

struct Rectangle
{
  double length, width;
};

struct Circle
{
  double radius;
};

struct Cube
{
  double side;
};

struct Prism
{
  double length, width, height;
};

struct Cylinder
{
  double radius, height;
};

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



  cout << "Lab 2b, Encapsulating Data b\n";
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
      Square* s=new Square;
      s->side=atof(token[1]);
      shapes[counter]=s;
      shapeID[counter]=1;

    }

    //if a rectangle create pointer to square and add to array

    else if(strcmp(token[0],"RECTANGLE")==0)
    {
      Rectangle* r=new Rectangle;
      r->length=atof(token[1]);
      r->width=atof(token[2]);
      shapes[counter]=r;
      shapeID[counter]=2;
    }

    //if a circle create pointer to square and add to array
    else if (strcmp(token[0],"CIRCLE")==0)
    {
      Circle* c=new Circle;
      c->radius=atof(token[1]);
      shapes[counter]=c;
      shapeID[counter]=3;
    }

    //if a cube create pointer to square and add to array
    else if (strcmp(token[0],"CUBE")==0)
    {
      Cube* cub=new Cube;
      cub->side=atof(token[1]);
      shapes[counter]=cub;
      shapeID[counter]=4;

    }

    //if a prism create pointer to square and add to array
    else if(strcmp(token[0],"PRISM")==0)
    {
      Prism* p=new Prism;
      p->length=atof(token[1]);
      p->width=atof(token[2]);
      p->height=atof(token[3]);
      shapes[counter]=p;
      shapeID[counter]=5;
    }

    //if a cylinder create pointer to square and add to array
    else if(strcmp(token[0],"CYLINDER")==0)
    {
      Cylinder* cy=new Cylinder;
      cy->radius=atof(token[1]);
      cy->height=atof(token[2]);
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
      outputSquare((Square*)shapes[x]);
    }
    else if(shapeID[x]==2)
    {
      outputRectangle((Rectangle*)shapes[x]);
    }
    else if(shapeID[x]==3)
    {
      outputCircle((Circle*)shapes[x]);
    }
    else if(shapeID[x]==4)
    {
      outputCube((Cube*)shapes[x]);
    }
    else if(shapeID[x]==5)
    {
      outputPrism((Prism*)shapes[x]);
    }
    else if(shapeID[x]==6)
    {
      outputCylinder((Cylinder*)shapes[x]);
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


void outputSquare(Square* a)
{
  double perimeter, area, side;
  side=a->side;
  perimeter=4*side;
  area=side*side;

  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);

  cout<<"SQUARE Side="<<side;

  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  cout<<" Perimeter="<<perimeter<<" Area="<<area<<endl;
}

void outputRectangle(Rectangle* a)
{
  double length, width, area, perimeter;
  length=a->length;
  width=a->width;
  area=length*width;
  perimeter=(2*length)+(2*width);

  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);

  cout<<"Rectangle length="<<length<<" width="<<width;

  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  cout<<" area="<<area<<" perimeter="<<perimeter<<endl;

}

void outputCircle(Circle* a)
{
  double radius, circumference, area;
  radius=a->radius;
  circumference=2*3.14*radius;
  area=3.14*radius*radius;

  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);

  cout<<"Circle Radius="<<radius;

  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  cout<<" Area="<<area<<" Circumference="<<circumference<<endl;
}

void outputCube(Cube* a)
{
  double side, volume, surfacearea;
  side=a->side;
  surfacearea=6*side*side;
  volume=side*side*side;

  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);

  cout<<"Cube Side="<<side;

  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  cout<<" Surface Area="<<surfacearea<<" Volume="<<volume<<endl;
}

void outputPrism(Prism* a)
{
  double length, width, height, surfacearea, volume;
  length=a->length;
  width=a->width;
  height=a->height;
  surfacearea=(2*width*height)+(2*width*length)+(2*length*height);
  volume=(height*length*width);

  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);

  cout<<"Prism Length="<<length<<" Width="<<width<<" Height="<<height;

  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  cout<<" Surface Area="<<surfacearea<<" Volume="<<volume<<endl;
}

void outputCylinder(Cylinder* a)
{
  double height, radius, surfacearea, volume;
  height=a->height;
  radius=a->radius;
  volume=(3.14*radius*radius*height);
  surfacearea= (2*3.14*radius*height)+(2*3.14*radius*radius);

  cout.unsetf(ios::fixed|ios::showpoint);
  cout << setprecision(6);

  cout<<"Cylinder radius="<<radius<<" height="<<height;

  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  cout<<" surface area="<<surfacearea<<" volume="<<volume<<endl;
}


