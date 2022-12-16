#include "Game.h"

Game::Game()
{
    upper_hand = false;
}

//this roll will roll for the upper_hand variable for the player.
//upper hand determines whether the player attacks first or not.
void Game::roll()
{
    int RNG = 1+(int)(9*rand()/(RAND_MAX+1.0));
    if(RNG <= 6){
        upper_hand = true;
    }
    else{
        upper_hand = false;
    }
}

//this function changes the stage for monster and player, the player's level needed
//to be high enough to change the stage.
void Game::global_stagechange(Player &player_stats, Monster &monster_stats)
{
     int* battle_stats = new int[5];
     for(int i = 0; i < 5; i ++){
         battle_stats[i] = player_stats.get_stats()[i];
     }
     int stage = player_stats.get_stage();

     if(battle_stats[3] >= 20*stage && stage != 5){
        player_stats.stage_change();
        monster_stats.stage_change();
        cout << "Your poceeded to the next stage!" << endl;
     }
     else if(battle_stats[3] < 20*stage){
         cout << "Your level is too low!" << endl;
     }
     else{
         cout << "This is the final stage!" << endl;
     }

}

//this function is the major part of this program, it runs the battle between
//player and the monster, It uses the monster's move and player's move to know
//whether the player or the monster attacks or defences. This function will continue to run
//until either player or monster's HP dropped below zero.
bool Game::battle(Player Player_stats, Monster mon_stats)
{

    double player_stats[5];
    double monster_stats[5];
    for(int i = 0; i < 5; i ++){
        player_stats[i] = Player_stats.get_stats()[i];
        monster_stats[i] = mon_stats.get_stats()[i];
    }
    bool death = false;
    bool player_move;
    bool monster_move;
    int player_damage_dealt = player_stats[2] * (1 - (monster_stats[1] / 200));
    int monster_damage_dealt = monster_stats[2] * (1 - (player_stats[1] / 200));

    if(upper_hand){


        cout << "You attacked first!" << endl;

        while(player_stats[0] > 0 && monster_stats[0] > 0){
            if(Player_stats.move()){
              cout << "You chose to attack" << endl;
                monster_move = mon_stats.move();
              if(!monster_move){
                    cout << "Monster defences" << endl;
                   monster_stats[0] = monster_stats[0] - player_damage_dealt * 0.8;
                   cout << "You dealt " << player_damage_dealt * 0.8 << " damage to the monster" << endl;
                }else{
                    monster_stats[0] = monster_stats[0] - player_damage_dealt;
                    cout << "You dealt " << player_damage_dealt << " damage to the monster" << endl;
                }

                if(monster_stats[0] > 0 && monster_move){
                    player_stats[0] = player_stats[0] - monster_damage_dealt;
                   cout << "Monster attacks" << endl;
                    cout << "The monster dealt " << monster_damage_dealt  << " damage to you" << endl;
                }
            }else{
                cout << "You chose to defense" << endl;
                if(monster_move){
                    player_stats[0] = player_stats[0] - monster_damage_dealt * 0.8;
                    cout << "Monster attacks" << endl;
                    cout << "The monster dealt " << monster_damage_dealt * 0.8  << " damage to you" << endl;
                }else{
                    cout << "Monster defences" << endl;
                    cout << "Nothing happened. . ." << endl;
                }
            }


        }
        if(player_stats[0] <= 0){
        death = true;
        }
        else if(monster_stats[0] <= 0){
        death = false;
        }

        Player_stats.set_hp(player_stats[0]);

        return death;
    }

    else{
        cout << "The monser attacked first!" << endl;
        while(player_stats[0] > 0 && monster_stats[0] > 0){
            if(mon_stats.move()){
                cout << "The monster chose to attack" << endl;
                player_move = Player_stats.move();
                if(!player_move){
                    cout << "You chose to defence" << endl;
                    player_stats[0] = player_stats[0] - monster_damage_dealt * 0.8;
                    cout << "The monser dealt " << monster_damage_dealt * 0.8 << "damage to you";
                }else{
                    player_stats[0] = player_stats[0] - monster_damage_dealt;
                    cout << "The monster dealt " << monster_damage_dealt << "damage to you";
                }

                if(player_stats[0] > 0 && player_move){
                    player_stats[0] = player_stats[0] - monster_damage_dealt;
                    cout << "You chose to attack" << endl;
                    cout << "You dealt " << player_damage_dealt  << " damage to the monster" << endl;
                }
            }else{
                cout << "The monster chose to defense" << endl;

                if(player_move){
                    monster_stats[0] = monster_stats[0] - player_damage_dealt * 0.8;
                    cout << "You chose to attack" << endl;
                    cout << "You dealt " << player_damage_dealt * 0.8  << " damage to the monster" << endl;
                }else{
                    cout << "You chose to defence" << endl;
                    cout << "Nothing happened. . ." << endl;
                }

            }

        }

        if(player_stats[0] <= 0){
            death = true;
        }
        else if(monster_stats[0] <= 0){
            death = false;
        }

        Player_stats.set_hp(player_stats[0]);

        return death;
    }

}

//This function is run after the battle function finished running, and it adds the exp and weapon
//dropped by the monster to the player's inventory, and it outputs special lines when the player had beaten
//the demon lord and the game will be finished.
bool Game::battle_end(Player &Player_stats, Monster mon_stats, bool death, Inventory &Player_inven)
{
    //int chance = 1+(int)(9*rand()/(RAND_MAX+1.0));
    string wep_nam = mon_stats.get_wep_name();
    int wep_id = mon_stats.get_wep_id();
    if(!death){
        cout << "You defeated the monster!" << endl;
        cout << "You received " << mon_stats.get_exp() << " exp!" << endl;
        Player_stats.set_exp(mon_stats.get_exp());
        //if(chance >= 3.5){
        //}
        cout << "The monster dropped a " << mon_stats.get_wep_name() << endl;

        if(mon_stats.get_gameend()){
            cout << "You have beaten the demon lord!" << endl;
            cout << "Thus, this ends your adventure." << endl;
            death = true;
        }
        Player_inven.add_drop(wep_nam, wep_id);

    }

    return death;
}




Game::~Game()
{
}
