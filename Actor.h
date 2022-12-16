//This class is the Actor class, it is responsible for the stat change
//of the player after a battle and it is the parent class of both the Player
//and Monster class.

#ifndef ACTOR_H
#define ACTOR_H
#include<string>
using namespace std;

class Actor
{
    protected:
    int stats[5];
    char Name[11];
    int stage;

    public:

    void stage_change();
    int get_stage();
    void set_stats(int HP, int Defense, int Strength, int level, int ex_points);
    ~Actor();
    virtual int* get_stats()=0;
    virtual bool move()=0;


};
#endif