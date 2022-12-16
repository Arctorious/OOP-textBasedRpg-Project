#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "Actor.h"
#include "Monster.h"
using namespace std;

class Monster;

class Player: public Actor
{
    public:

    Player();
    int current_weapondmg;
    int* battle_stats;


    //Inventory Player_inentory


    void set_damage(int weaponid);
    void rest();
    void set_exp(int ex_point);
    void setname();
    void check_level();
    void display_stats();
    void set_hp(int battle_stat);
    void set_xp(int xp);
    string stages[5];

    virtual int* get_stats();
    virtual bool move();
    ~Player();
};
#endif





