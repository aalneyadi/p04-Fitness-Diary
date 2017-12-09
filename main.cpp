#include "food.h"
#include "activity.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void loadMenu();

void mainMenu(int calsConsumed,int calsAllowed);

bool loadFile(string fileName,vector<Food>& foods, 
    vector<Activity>& activities,int& caloriesConsumed, 
    int& caloriesAllowed);

Food getFood();

Activity getActivity();


int main()
{
  vector<Food> foods;
  vector<Activity> activities;
  int caloriesAllowed = 0;
  int caloriesConsumed = 0;
  int cmd = 0;
  string enter;

  while (cmd<1||cmd>2)
  {
    loadMenu();
    cin>>cmd;
    cin.ignore();
    if (cmd<1||cmd>2)
      cout<<"Please choose 1 or 2!"<<endl;
  }

  if (cmd==1)
  {
    while (caloriesAllowed<=0||caloriesAllowed>10000)
    {
      cout<<"Enter daily calorie allowance: ";
      cin>>caloriesAllowed;
      cin.ignore();
      cout<<endl;
        
      if (caloriesAllowed<=0)
        cout<<"Please enter amount higher than 0!"<<endl;
      else if (caloriesAllowed>10000)
        cout<<"Please enter amount less than 10,000!"<<endl;
    }
  } else if (cmd==2)
  {
    bool fail=true;
    string fileName;

    while (fail)
    {
      cout<<"Filename: ";
      getline(cin,fileName);

      if (loadFile(fileName,foods,activities,caloriesConsumed, 
            caloriesAllowed))
      {
        cout<<"Loaded profile from "<<fileName<<"."<<endl;
        fail = false;
      }
      else
      {
        cout<<"Could not open "<<fileName<<"."<<endl;
        cout<<endl;
        fail = true;
      }
    }
  }

  while (cmd!=6)
  {
    mainMenu(caloriesConsumed,caloriesAllowed);
    cin>>cmd;
    cin.ignore();
    cout<<endl;

    switch (cmd)
    {
      case 1:
        {
          Food temp = getFood();
          bool exists = false;

          for (int i=0;i<foods.size()&&!exists;i++)
          {
            if (temp.getName()==foods[i].getName())
            {
              foods[i].setCount(foods[i].getCount()+1);
              exists = true;
            }
          }

          if (!exists)
          {
            foods.push_back(temp);
            foods[foods.size()-1].setCount(1);
          }

          caloriesConsumed+=temp.getCalories();
        }
        break;

      case 2:
        {
          Activity temp = getActivity();
          activities.push_back(temp);
          caloriesConsumed-=temp.getBurnRate()*temp.getDuration();
        }
        break;

      case 3:
        if (foods.empty())
          cout<<"You have not logged any foods yet!"<<endl;
        else
          for (int i=0;i<foods.size();i++)
          {
            foods[i].display();
            cout<<endl;
          }

        break;

      case 4:
        if (activities.empty())
          cout<<"You have not logged any exercise activities yet!" 
            <<endl;
        else
          for (int i = 0;i< activities.size();i++)
          {
            activities[i].display();
            cout<<endl;
          }
        break;

      case 5:
        {
          if (activities.empty()&&foods.empty())
            cout<<"There is no data to save!"<<endl;
          else
          {
            string filename;
            cout<<"Filename: ";
            cin>>filename;
            cin.ignore();

            ofstream f(filename);

            f<<caloriesConsumed<<"/"<<caloriesAllowed<<endl;
            f<<foods.size()<<"-"<<activities.size()<<endl;

            for (int i = 0;i<foods.size();i++)
              f <<foods[i].getCategory()<<"-"<<foods[i].getName() 
                <<"-"<<foods[i].getCalories()<<endl;
            cout<<"#"<<endl;

            for (int i=0;i<activities.size();i++)
              f <<activities[i].getCategory()<<"-" 
                <<activities[i].getName()<<"-"
                <<activities[i].getBurnRate()<<"-"
                <<activities[i].getDuration()
                <<endl;

            f.close();

            cout<<"Saved the data to \""<<filename <<"\""<<endl;
          }
        }

        break;

      case 6:
        cout<<"Goodbye!"<<endl;
        break;

      default:
        cout<<"Invalid selection"<<endl;
        break;
    }
    
    if (cmd!=6)
    {
      cout<<endl
        <<"Enter to continue";

      getline(cin,enter);
    }
  }

  return 0;
}

void loadMenu()
{
  cout
    <<endl
    <<"1-Start new day"<<endl
    <<"2-Load day from file"<<endl
    <<endl
    <<">>>>";
}

void mainMenu(int consumed,int allowed)
{
  cout 
    <<endl
    <<"-----------------"<<endl
    <<"| FITNESS DIARY |"<<endl
    <<"-----------------"<<endl
    <<"1-Food entry"<<endl
    <<"2-Log exercise"<<endl
    <<"3-View nutrition"<<endl
    <<"4-View physical activity"<<endl
    <<"5-Save data"<<endl
    <<"6-Quit"<<endl
    <<endl
    <<"[ "<<consumed<<"/"<<allowed<<" calories consumed ]"<<endl
    <<endl
    <<">>>>";
}

bool loadFile(string fileName,vector<Food>& foods, 
    vector<Activity>& activities,int& caloriesConsumed, 
    int& caloriesAllowed)
{
  string name;
  string category;
  int calories;
  int burnRate;
  int duration;
  int foodAmt,actAmt;

  ifstream f(fileName);

  if (!f)
  {
    f.close();
    return false;
  }
  else
  {
    f>>caloriesConsumed;
    f.ignore();
    f >>caloriesAllowed;
    f.ignore();
    f >>foodAmt;
    f.ignore();
    f >>actAmt;
    f.ignore();

    for (int i=0;i<foodAmt;i++)
    {
      getline(f,name,'-');
      getline(f,category,'-');
      f >>calories;
      f.ignore();
      Food tempFood(name,category,calories);
      foods.push_back(tempFood);
    }
    
    for (int i=0;i<actAmt;i++)
    {
      getline(f,name,'-');
      getline(f,category,'-');
      f>>burnRate;
      f.ignore();
      f>>duration;
      f.ignore();
      Activity tempAct(name,category,burnRate,duration);
      activities.push_back(tempAct);
    }

    f.close();
    return true;
  }
}

Food getFood()
{
  string name;
  string category;
  int calories;

  cout<<"Please enter the food type: ";
  getline(cin,category);
  cout<<"What did you eat? ";
  getline(cin,name);
  cout<<"How many calories does it have? ";
  cin>>calories;
  cin.ignore();

  Food temp(name,category,calories);

  return temp;
}

Activity getActivity()
{
  string name;
  string category;
  int burnRate;
  int duration;

  cout<<"Please enter the type of activity: ";
  getline(cin,category);
  cout<<"What did you do? ";
  getline(cin,name);
  cout<<"How many calories does this activity burn per minute? ";
  cin>>burnRate;
  cin.ignore();
  cout<<"How many minutes you did this activity? ";
  cin>>duration;
  cin.ignore();

  Activity temp(name,category,burnRate,duration);

  return temp;
}
