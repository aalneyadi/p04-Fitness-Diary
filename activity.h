#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
using namespace std;

class Activity
{
  public:
    Activity(string n,string cat,int br,int d);
    string getName();
    string getCategory();
    int getBurnRate();
    int getDuration();
    void setName(string n);
    void setCategory(string c);
    void setBurnRate(int br);
    void setDuration(int d);
    void display();

  private:
    string name;
    string category;
    int burnRate;
    int duration;
};

#endif
