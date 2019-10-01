#include <cstdlib>
#include "playerClass.h"

class Monster
{
    public:
    std::string type;
    int damage;
    int health;
    
    int attack(Player player, Monster monster)
    {
        if ((rand() % 20 + 1) >= 12)
        {
            player.health -= monster.damage;
            std::cout << "The " << monster.type << " strikes you" <<std::endl;
        }
        else
        {
            std::cout << "You manage to dodge the " << monster.type <<"'s attack" <<std::endl;
        }
    return 1;
    }
};