#include <cstdlib>

class Monster
{
    public:
    std::string type;
    int damage;
    int health;
    int * player_health_ptr;
    
    int attack(Monster monster)
    {
        if ((rand() % 20 + 1) >= 12)
        {
            *player_health_ptr -= monster.damage;
            std::cout << "Your enemy strikes you" <<std::endl;
        }
        else
        {
            std::cout << "You manage to dodge your enemies attack" <<std::endl;
        }
    return monster.health;
    }
};

class Player
{
    public:
    int damage;
    int health;
        
    int attack(Player player, Monster monster)
    {
        if ((rand() % 20 + 1) >= 10)
        {
            monster.health -= player.damage;
            std::cout << "Your enemy reels in pain" <<std::endl;
        }
        else
        {
            std::cout << "You miss your enemy" <<std::endl;
        }
    return monster.health;
    }
};