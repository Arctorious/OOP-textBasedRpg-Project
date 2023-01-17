#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Game.h"
#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    bool death = false;
    char command;
    Player user = Player();
    Game global = Game();
    Monster computer = Monster();

    int* battle_stats = user.get_stats();

    Inventory player_inven = Inventory();
    char command2;
    bool end = false;
    bool inv_check;



    user.setname();

    while(death == false){
        cout << "What would you like to do today?" << endl;
        cout << "Input 1 for explore | 2 for rest | 3 for displaying your stats | 4 for accessing your inventory." << endl;
        cout << "Please input 5 if you wish to proceed to the next stage" << endl;
        cout << "please input 0 if you wish to end the game" << endl;
        cin >> command;
        while(command != '0' && command != '1' && command != '2' && command != '3' && command != '4' && command != '5' && command != 'g'){
        cout << "invalid command! Enter again !" << endl;
        cin >> command;
        }
        if(command == '0'){
            death = true;
        }
        //cheat code to increase the player's level
        if(command == 'g')
        {
            user.set_xp(100000);
            user.check_level();
        }
        else if(command == '5'){
            global.global_stagechange(user, computer);
        }
        else if(command == '3'){
            user.display_stats();
        }
        else if(command == '2'){
            user.rest();
        }
        else if(command == '1'){

            computer.Monster_spawn(battle_stats);
            global.roll();
            death = global.battle(user, computer);
            death = global.battle_end(user, computer, death, player_inven);
            user.check_level();
        }
        else if(command == '4'){

        inv_check = player_inven.disp_inven();



            while(end == false){
                cout << "If you wish to discard a weapon, enter 1." << endl;
                cout << "If you wish to equib a weapon, enter 2." << endl;
                cout << "If you don't wish to do anything, enter 3." << endl;
                cin >> command2;
                if(command2 != '1' && command2 != '2' && command2 != '3'){
                    cout << "Wrong command, enter again!" << endl;
                }
                else if(command2 == '1'){
                    player_inven.discarded();
                }
                else if(command2 == '2'){
                    player_inven.change_weapons();
                    user.set_damage(player_inven.get_wepId());
                }
                else if(command2 == '3'){
                    end = true;
                }
            }
        }
    }
        cout << "Game over" << endl;

        cout << endl;

        cout << "gg" << endl;
    return 0;

}



