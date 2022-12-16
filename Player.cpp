#include "Player.h"
#include "Monster.h"
#include "Actor.h"

Player::Player()
{
    stats[0] = 100;
    stats[1] = 10;
    stats[2] = 15;
    stats[3] = 1;
    stats[4] = 100;

    stage = 1;
    current_weapondmg = 0;

    battle_stats = new int[5];
    battle_stats[0] = stats[0];
    battle_stats[1] = stats[1];
    battle_stats[2] = stats[2] + current_weapondmg;
    battle_stats[3] = stats[3];
    battle_stats[4] = 0;
}
//this function sets the damage of the player after the player
//changed a weapon
void Player::set_damage(int weaponid)
{
    current_weapondmg = weaponid*5;
    battle_stats[2] = stats[2] + current_weapondmg;
}

//this function displays the stats of the player.
void Player::display_stats()
{
    string stat_name[5] = {"HP", "Defense", "Strength", "level", "curret exp"};
    for(int i = 0; i < 5; i ++){
        cout << stat_name[i] <<": "<< battle_stats[i] << "/" << stats[i] << endl;
    }
}


//this function sets the HP of the player, which is
//battle_stats[0] to max HP (which is stats[0])
void Player::rest()
{
    battle_stats[0] = stats[0];
}

//this sets the xp of the player, and its mostly for
//testing purposes
void Player::set_xp(int xp)
{
    battle_stats[4] = xp;
}

//this function sets the name of the player
void Player::setname()
{
    cout << "Please enter your name: " << endl;
    cin >> Name;
}

//this function returns the battle_stats of player,
//and its pure virtual because it returns different
//variables (it returns the stats array for the monster as well
//but the stats array for player is the max stats, and it shouldn't
//be modified, thus a different array, battle_stats, is returned.
int* Player::get_stats()
{
    return battle_stats;
}

//this sets the hp of the player after a battle.
void Player::set_hp(int battle_stat)
{
    battle_stats[0] = battle_stat;
}

//this increases the exp of the player after a battle
void Player::set_exp(int ex_point)
{
    stats[4] = stats[4] + ex_point;
}

//this function will be checking the player's level after a
//battle, it will level up the player as long as the player's
//current exp is higher than the exp required to level up.
void Player::check_level()
{
    while(battle_stats[4] >= stats[4]){

        cout << "You leveled up!" << endl;

        battle_stats[4] = battle_stats[4] - stats[4];

        stats[0] = stats[0] + 10;
        stats[1] = stats[1] + 2;
        stats[2] = stats[2] + 3;
        stats[3] = stats[3] + 1;
        stats[4] = stats[4] + 5;

        for(int i = 0; i < 4; i ++){
            battle_stats[i] = stats[i];
        }

    }
}
//this function changes the battle_stats of the player
//based on user inputs, additionally it outputs the false or
//true attack command that will be used in the Game class.
//this function is pure virtual, as it will require user input,
//unlike the Monster's function.
bool Player::move()
{
    char command;
    bool attack;
    bool false_command = 1;
    cout << "Please input your move" << endl;
    cout << "1. Attack || 2. Defense" << endl;
    cin >> command;
    while(false_command == 1){
        if(command != '1'&& command != '2'){
            false_command = 1;
            cout << "Invalid input! Please enter again!" << endl;
            cout << "1. Attack || 2. Defense" << endl;
            cin >> command;
        }
        else{
            false_command = 0;
            if(command == '1'){
                attack = true;
            }
            else{
                attack = false;
            }
        }
    }
    return attack;
}

Player::~Player()
{
}