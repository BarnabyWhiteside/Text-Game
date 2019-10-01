#include <iostream>
#include <string>
#include <cstring>
#include "menuFunc.h"
#include "database.h"
#include "gameFunctions.h"
#include "battleMenu.h"
using namespace std;

int num = 1;
int main(int num)
{
  string user;
  user = printMenu(accessDatabase("SELECT * FROM Rooms;", 2, num).c_str());
  int forward = num +1;
  int og = num;
  int back = num -1;
  int ranMonst = ranNum5();


if (user == "North")
{
  if (ranNum100() > 50 && (accessDatabase("SELECT * FROM Exits;", 2, num) == "1"))
  {
      battleMenu(accessDatabase("SELECT * FROM Monster;",3,ranMonst).c_str());
  }

  if (accessDatabase("SELECT * FROM Exits;", 2, num) == "1")
  {
   main(forward);
  }
  else if (accessDatabase("SELECT * FROM Exits;", 2, num) == "0")
  {
    printMenu("This door is locked");
    main(og);
  }
  else
  {
    main(back);
  }
}
else if (user == "East")
{
  if (ranNum100() > 50 && (accessDatabase("SELECT * FROM Exits;", 3, num) == "1"))
  {
    battleMenu(accessDatabase("SELECT * FROM Monster;",3,ranNum5()).c_str());
  }

  if (accessDatabase("SELECT * FROM Exits;", 3, num) == "1")
  {
   main(forward);
  }
   else if (accessDatabase("SELECT * FROM Exits;", 3, num) == "0")
   {
     printMenu("This door is locked");
     main(og);
   }
   else
   {
      main(back);
   }

}
else if (user == "South")
{
  if (ranNum100() > 50 && (accessDatabase("SELECT * FROM Exits;", 4, num) == "1"))
  {
    battleMenu(accessDatabase("SELECT * FROM Monster;",3,ranNum5()).c_str());
  }

  if (accessDatabase("SELECT * FROM Exits;", 4, num) == "1")
  {
   main(forward);
  }
   else if (accessDatabase("SELECT * FROM Exits;", 4, num) == "0")
   {
     printMenu("This door is locked");
     main(og);
   }
   else
   {
      main(back);
   }
}

else if (user == "West")
{
  if (ranNum100() > 50 && (accessDatabase("SELECT * FROM Exits;", 5, num) == "1"))
  {
    battleMenu(accessDatabase("SELECT * FROM Monster;",3,ranNum5()).c_str());
  }

  if (accessDatabase("SELECT * FROM Exits;", 5, num) == "1")
  {
   main(forward);
  }
   else if (accessDatabase("SELECT * FROM Exits;", 5, num) == "0")
   {
     printMenu("This door is locked");
     main(og);
   }
   else
   {
      main(back);
   }
}

else
{
  return 0;
}

}
