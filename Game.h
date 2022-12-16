#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Monster.h"
#include "Actor.h"
#include "Inventory.h"
#include <iostream>

using namespace std;

class Game
{
    public:
    bool upper_hand;

    Game();
    void roll();
    bool battle(Player Player_stats, Monster mon_stats);
    bool battle_end(Player &Player_stats, Monster mon_stats, bool death, Inventory &Player_inven);
    void global_stagechange(Player &player_stats, Monster &monster_stats);
    ~Game();


};
#endif