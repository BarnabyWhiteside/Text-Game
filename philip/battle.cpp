#include <iostream>
#include <cstdlib>
#include "battleClasses.h"

int check_health(Player player, Monster monster)
{
    if (player.health <= 0)
    {
        std::cout << "As the last light enters your eyes, you realise that you have been killed" << std::endl;
        return 1;
    }
    else if (monster.health <= 0)
    {
        std::cout << "You attack your enemy and it falls limp" <<std::endl;
        return 2;
    }
    
    return 0;
}

int main()
{
    Player player;
    player.damage = 10;
    player.health = 30;
    Monster monster;
    monster.health = 20;
    monster.damage = 10;
    monster.player_health_ptr = &player.health;
    while (check_health(player, monster) == 0)
    {
        monster.health = player.attack(player, monster);
        monster.health = monster.attack(monster);
    }
    return 0;
}