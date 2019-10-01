#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include "menuFunc.h"
#include "database.h"
#include "battleMenu.h"
#include "BWgameFunc.h"
#include "damageMenu.h"
#include "inventoryMenu.h"
using namespace std;


int main()
{
  string user;
  user = printMenu(accessDatabase("SELECT * FROM Rooms;", 2, 1).c_str());

if (user == "North")
{
   inventoryMenu("Inventory");
}
else if (user == "East")
{
   printMenu("This door is locked");
   main();
}
else if (user == "West" || user == "South")
{
   printMenu("There is no door this way");
   main();
}
else
{
  return 0;
}

}
