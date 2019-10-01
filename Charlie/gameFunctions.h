#include <iostream>
#include <string>
#include <cstring>
#include <time.h>


using namespace std;

int ranNum100 ()
{
  srand (time(NULL));
  return rand() %100 +1;
}

int ranNum5 ()
{
  srand (time(NULL));
  return rand() %5 +1;
}


string playerHealth(int ogHealth,int dmg)
{
  int health = ogHealth - dmg;
  string title = "The monster damaged you, your health is now " + to_string(health);
  return title;
}
