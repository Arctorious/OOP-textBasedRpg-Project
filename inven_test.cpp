#include <iostream>
#include "Inventory.h"
#include "Player.h"
int main(){
    Inventory player_inven = Inventory();
    Player user = Player();
    char command;
    bool end = false;
    bool inv_check;
    inv_check = player_inven.disp_inven();



    while(end == false){

        cout << "If you wish to discard a weapon, enter 1." << endl;
        cout << "If you wish to equib a weapon, enter 2." << endl;
        cout << "If you don'wish to do anything, enter 3." << endl;
        cin >> command;
        if(command != '1' && command != '2' && command != '3'){
            cout << "Wrong command, enter again!" << endl;
        }
        else if(command == '1'){
            player_inven.discarded();
        }
        else if(command == '2'){
            player_inven.change_weapons();
            user.set_damage(player_inven.get_wepId());
        }
        else if(command == '3'){
            end = true;
        }


    }

    return 0;
}