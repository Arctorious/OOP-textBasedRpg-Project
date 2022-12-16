#include "Monster.h"
#include "Player.h"
#include "Actor.h"
using namespace std;

Monster::Monster()
{

    stats[0] = 0;
    stats[1] = 0;
    stats[2] = 0;
    stats[3] = 0;
    stats[4] = 0;
    stage = 1;

    mon_name[0] = "Slime";
    mon_name[1] = "Goblin";
    mon_name[2] = "Zombie";
    mon_name[3] = "Goblin King";
    mon_name[4] = "Death knight";
    mon_name[5] = "Fire drake";
    mon_name[6] = "Frost dragon";
    mon_name[7] = "Gargoyle";
    mon_name[8] = "Great devil";
    mon_name[9] = "Demon lord";

    weapons[0] = "Nothing";
    weapons[1] = "wooden sword";
    weapons[2] = "rusty axe";
    weapons[3] = "iron claw";
    weapons[4] = "Stone mace";
    weapons[5] = "Riven";
    weapons[6] = "Broken hero sword";
    weapons[7] = "Master mage's stone hammer";
    weapons[8] = "True hero sword";
    weapons[9] = "A stick";

    if_gameover = false;
}

//it gets the weapon name of the weapon dropped from the monster.
string Monster::get_wep_name()
{
    return weaponDrop;
}

//this gets the weapon id of the weapon dropped from the monster.
//weapon id is associated to the weapon damage for the player, which
//was zero before the inventory was implemented.
int Monster::get_wep_id()
{
    return wep_id;
}

//this gets the gameover variable, the game finishes if it
//returns true.
bool Monster::get_gameend()
{
    return if_gameover;
}

//this gets the amount of exp dropped from the monster after a battle.
int Monster::get_exp()
{
    return stats[4];
}

//this returns the stats of the monster, as explained in the Player class,
//this function is pure virtual as it would return different arrays for
//Monster and Player.
int* Monster::get_stats()
{
    return stats;
}

//this function generated the monster's move from a randomised variable.
//if num is above or small and equalls to 6, then the monster attacks, else
//the monster does not attack. This function is pure virtual, and does not
//require user inputs unlike the Player's function.
bool Monster::move()
{
    num = 1+(int)(10.0*rand()/(RAND_MAX+1.0));  //form rand number to check whether to attack player
    if( num>0 && num <= 6){
        Monster_attack = true;      //monster will attack player
    }
    else{
        Monster_attack = false;
    }
    return Monster_attack;
}

//the function below spawns monsters with different name and stats based on the player's level.
//as the player's level becomes higher, stronger monsters will spawn, but it would not get stronger
//unless the player changes the stage.
void Monster::Monster_spawn(int* player_stats)
{
    int base_stats[5] = {100, 5, 9, 1, 30};
    int monster_type = 1;
    int n = 10;
    if(player_stats[3] <= n*((stage * 2) - 1) ){
        monster_type = 1*(stage * 2) - 1;
        for(int i = 0; i < 5; i ++){
            stats[i] = base_stats[i] * monster_type;
        }
    }
    else if(player_stats[3] >= n*((stage * 2) - 1) ){
        monster_type = stage * 2;
        for(int i = 0; i < 5; i ++){
            stats[i] = base_stats[i] * monster_type;
        }
        if(monster_type == 10){
            if_gameover = true;
        }
    }
    monster_name = mon_name[monster_type - 1];
    weaponDrop = weapons[monster_type - 1];
    wep_id = monster_type;

    cout << monster_name << " has appeared!" << endl;
}

Monster::~Monster()
{

}
