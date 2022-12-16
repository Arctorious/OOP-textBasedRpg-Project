#include "Actor.h"

//this function sets the stats of the player and monster class
//this function is mostly for testing.
void Actor::set_stats(int HP, int Defense, int Strength, int level, int ex_points)
{
    stats[0] = HP;
    stats[1] = Defense;
    stats[2] = Strength;
    stats[3] = level;
    stats[4] = ex_points;

}
//these two function is for the stage change
//of this program.
//the function below changes the stage.
void Actor::stage_change()
{
    stage = stage + 1;
}
//this function gets the stage for monster and player.
int Actor::get_stage()
{
    return stage;
}


Actor::~Actor()
{

}