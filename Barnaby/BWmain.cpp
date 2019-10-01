#include <iostream>
#include <string>
#include <cstring>
#include "database.h"
#include "battleMenu.h"
#include "damageMenu.h"
#include "BWgameFunc.h"
using namespace std;

int main()    //function to simulate an encounter with a monster
{
  string user;    //variable to check what the player selects in the menu
  int playerLocalHealth = 0;    //keeps track locally of the player's health
  int playerDamage = 0;   //keeps track locally of the players damage
  int monsterLocalHealth = 0;   //keeps track of the monster's health
  int monsterDamage = 0;    //keeps track of the monster's damage
  bool loop = 1;
  int monstID = ranNum5();    //picks a random number

  damageMenu(accessDatabase("SELECT * FROM Monster;", 3,monstID).c_str());    //takes the description of the random monster from the database

  while (loop == 1)   //starts an infinite loop
  {
    playerLocalHealth += playerDamage;    //calulates player health after damage
    user = battleMenu(playerHealthTotal(playerLocalHealth).c_str());    //shows the players health
    if (playerHealthTotal(playerLocalHealth) == "You are Dead")   //checks if player is alive
    {
      return 0;
    }
    else if (user == "Attack")    //player attacks the monster
    {
      playerDamage += stoi(accessDatabase("SELECT * FROM Monster;", 5, monstID));   //calulates damage done to player
      monsterDamage += stoi(accessDatabase("SELECT * FROM ItemEffects;", 2, 4));    //caluculate damage done to monster
      damageMenu(monsterHealth(monsterLocalHealth).c_str());    //describes player attacking monster
      damageMenu(playerHealth(playerLocalHealth).c_str());    //describes monster attacking player
    }
    else if (user == "Defend")    //player defends the monsters attack
    {
      playerDamage += (stoi(accessDatabase("SELECT * FROM Monster;", 5, monstID)) - stoi(accessDatabase("SELECT * FROM ItemEffects;", 3, 2)) * 0.5);    //calculates damage done to player
      damageMenu(defPlayerHealth(playerLocalHealth).c_str());   //describes player defending monster
    }
    else if (user == "Inventory")   // player opens inventory to be added
    {
      break;
    }
    else    //player exits
    {
      break;
    }

  }
}
