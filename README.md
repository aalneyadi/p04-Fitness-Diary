# p04-Fitness-Diary
fitness diary is a program to log nutrition and physical activity to keep track of how many calories are burned and consumed in a day.

## Input/Output
[main.cpp lines 33 - 320] ([/main.cpp#L33](/main.cpp#L33 "main.cpp"))

[food.cpp lines 55 & 61] ([/food.cpp#L55](/food.cpp#L55 "food.cpp"))

[activity.cpp line 55] ([/activity.cpp#L55](/activity.cpp#L55 "activity.cpp"))

I used cin statements to get the input from the user and used cout statements to display the program to the user.

## Control Flow
[main.cpp lines 35 - 247] ([/main.cpp#L35](/main.cpp#L35 "main.cpp"))

[food.cpp line 60] ([/food.cpp#L60](/food.cpp#L60 "food.cpp"))

I used a combination of if/else and switch for my control flow to direct the program based on the input from the user.

## Iteration
[main.cpp line 30] ([/main.cpp#L30](/main.cpp#L30 "main.cpp"))

[main.cpp line 92] ([/main.cpp#L92](/main.cpp#L92 "main.cpp"))

I use both for and while loops in the main function to repeat menus and to iterate through vectors.

## Data Structure
[main.cpp lines 103, 114, 265, 277] ([/main.cpp#L103](/main.cpp#L103 "main.cpp"))

I use 2 std::vector container to store the activities and foods that the user inputs from keyboard or read them from the file the user inputs.

## Function
[main.cpp lines 200 - 325] ([/main.cpp#L200](/main.cpp#L200 "main.cpp"))

[food.cpp lines 5 - 62] ([/food.cpp#L5](/food.cpp#L5 "food.cpp"))

[activity.cpp lines 5 - 58] ([/activity.cpp#L5](/activity.cpp#L5 "activity.cpp"))

In the Activity and Food classes I use functions for get and set functions to read and set the private variables in the classes. In the main.cpp file I made functions to help with user I/O.

## File IO
[main.cpp lines 154 & 240] ([/main.cpp#L154](/main.cpp#L154 "main.cpp"))

I use file I/O to read and write the information in the vectors and the calories information in the variables so that the user can re-load a profile when they open the program again.

## Class
[food.cpp line 7] ([/food.cpp#L7](/food.cpp#L7 "food.cpp"))

[activity.cpp line 7] ([/activity.cpp#L7](/activity.cpp#L7 "activity.cpp"))

In the fitness diary I use Activity objects and Food objects to store in the vector to store extra information for each type of object.
