// Lab 3A
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#include <cstdlib>

#include <iomanip>
using std::fixed;
using std::setprecision;

#include "SalesPerson.h"

SalesPerson::SalesPerson()
{
  for(int i=0; i<monthsPerYear; i++)
  {
    sales[i]=0.0;
  }
}

void SalesPerson::getSalesFromUser()
{
  double salesFigure;
  string buf;

  for(int i=1;i<=monthsPerYear;i++)
  {
    cout<<"Enter sales amount for month"<<i<<":";
    cin>>buf;
    salesFigure = atof(buf.c_str());
    setSales(i,salesFigure);
  }
}

void SalesPerson::setSales(int month, double amount)
{
  if(month >= 1 && month <= monthsPerYear && amount > 0)
  {
    sales[month-1]=amount;
  }
  else
  {
    cout<<"Invalid month or sales figure"<<endl;
  }
}

void SalesPerson::printAnnualSales()
{
  cout<<setprecision(2)<<fixed
    <<"\nThe total annual sales are: $"
    <<totalAnnualSales()<<endl;
}

double SalesPerson::totalAnnualSales()
{
  double total=0.0;

  for(int i=0; i<monthsPerYear; i++)
  {
    total+=sales[i];
  }

  return total;
}
