#include <iostream>
#include "food.h"
using namespace std;

Food::Food(string n,string cat,int cals)
{
  name = n;
  category = cat;
  calories = cals;
  count = 0;
}
    
string Food::getName()
{
  return name;
}

string Food::getCategory()
{
  return category;
}
    
int Food::getCalories()
{
  return calories;
}

int Food::getCount()
{
  return count;
}

void Food::setName(string n)
{
  name = n;
}

void Food::setCategory(string c)
{
  category = c;
}

void Food::setCalories(int c)
{
  calories = c;
}

void Food::setCount(int cnt)
{
  count = cnt;
}

void Food::display()
{
  cout<<"Category: "<<category<<endl
    <<"Name: "<<name<<endl
    <<"Calories: "<<calories<<endl
    <<"Qty.: "<<count<<endl;

  if (count>1)
    cout<<"("<<count*calories<<" calories total)"<<endl;
}
