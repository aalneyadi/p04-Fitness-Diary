#ifndef FOOD_H
#define FOOD_H

#include <string>
using namespace std;

class Food
{
  public:
    Food(string n,string cat,int cals);
    string getName();
    string getCategory();
    int getCalories();
    int getCount();
    void setName(string n);
    void setCategory(string c);
    void setCalories(int c);
    void setCount(int cnt);
    void display();

  private:
    string name;
    string category;
    int calories;
    int count;
};

#endif
