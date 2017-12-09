#include <iostream>
#include "activity.h"
using namespace std;

Activity::Activity(string n,string cat,int br,int d)
{
  name = n;
  category = cat;
  burnRate = br;
  duration = d;
}
    
string Activity::getName()
{
  return name;
}

string Activity::getCategory()
{
  return category;
}
    
int Activity::getBurnRate()
{
  return burnRate;
}

int Activity::getDuration()
{
  return duration;
}

void Activity::setName(string n)
{
  name = n;
}

void Activity::setCategory(string c)
{
  category = c;
}

void Activity::setBurnRate(int br)
{
  burnRate = br;
}

void Activity::setDuration(int d)
{
  duration = d;
}

void Activity::display()
{
  cout<<"Category: "<<category<<endl
    <<"Activity: "<< name<<endl
    <<"Calories burned: "<<burnRate*duration<<endl;
}
