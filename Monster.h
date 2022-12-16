#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include <iostream>
#include "Player.h"
#include "Actor.h"

using namespace std;

    class Player;

class Monster: public Actor
{
    public:

    string mon_name[10];
    string weaponDrop;
    int wep_id;
    string weapons[10];
    int expDrop;
    bool Monster_attack;
    int num;
    string monster_name;
    bool if_gameover;

    Monster();
    //string dropweapon();

    void Monster_spawn(int* player_stats);
    string get_wep_name();
    int get_wep_id();
    int get_exp();
    bool get_gameend();
    virtual int* get_stats();
    virtual bool move();
    ~Monster();
};
#endif