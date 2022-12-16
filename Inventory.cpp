#include "Inventory.h"

using namespace std;

//creares a 5x5 2d array.
Inventory::Inventory()
{
    inventory = new string[25];
    inventory_id = new int[25];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) {
            inventory[i*5 + j] = " ";
            inventory_id[i*5 + j] = 0;
        }
    }
    current_weaponname = " ";
    current_weaponid = 0;
}

Inventory::~Inventory()
{
}

//This function displays the item within the inventroy and the current weapon of the player.
bool Inventory::disp_inven()
{
    bool empty_inven = true;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(inventory[i*5 + j] != " "){
                if(j != 4){
                    cout << " | "<<inventory[i*5 + j];
                    empty_inven = false;
                }
                else{
                    cout << inventory[i*5 + j] << " | ";
                    empty_inven = false;
                }
            }
        }
        if(!empty_inven){
            cout << endl;
        }
    }

    if(empty_inven){
        cout << "Your inventory is empty!" << endl;
        cout << "Your current weapon is: " << current_weaponname << endl;
        cout << "Your current weapon's attack is: " << current_weaponid*5 << endl;
    }
    else{
       cout << "Your current weapon is: " << current_weaponname << endl;
        cout << "Your current weapon's attack is: " << current_weaponid*5 << endl;
    }

    return empty_inven;
}

//this fucntion discards the weapon based on player's input
void Inventory::discarded()
{
    string item_name;
    cout << "Enter the item name to discard: ";
    bool ret = false;
    while(ret == false){
        getline(cin, item_name);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (inventory[i*5 + j] == item_name) {
                    inventory[i*5 + j] = " ";
                    inventory_id[i*5 + j] = 0;
                    ret = true;
                    break;
                }
            }
            if(ret){
                break;
            }
        }
        if(ret == false){
            cout << "No such weapon in the inventory." << endl;
            cout << "Enter again: ";
        }
    }
}

//this adds the dropped weapon from battle_end in Game.cpp into the inventroy
//for the player.
//this function will also ask the player to discard an weapon if the inventory is full.
void Inventory::add_drop(string item_name, int item_id)
{
    bool full_inven;
    char command;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (inventory[i*5 + j] == " ") {
                inventory[i*5 + j] = item_name;
                inventory_id[i*5 + j] = item_id;
                return;
            }
        }
    }
    cout << "Inventory full." << endl;
    full_inven = true;
    bool dis;
    bool unuse = disp_inven();
    cout << "Enter 1 if you wish to discard an item" << endl;
    cout << "Enter 2 if you do not wish to discard an item" << endl;
    while(full_inven){
        cin >> command;
        if(command != '1' && command != '2'){
            cout << "wrong command, input again!" << endl;
        }
        else if(command == '1'){
            discarded();
            dis = true;
            full_inven = false;
        }
        else if(command == '2'){
            dis = false;
            full_inven = false;
        }
    }

    if(dis){
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (inventory[i*5 + j] == " ") {
                    inventory[i*5 + j] = item_name;
                    inventory_id[i*5 + j] = item_id;
                    return;

                }
            }

        }
    }

}


//this function changes the current weapon the player is equibing.
void Inventory::change_weapons()
{
    string weapon_name = current_weaponname;
    int item_id = current_weaponid;
    string find_item;
    bool ret = false;
    cout << "Enter the weapon name to equip: ";
    while(ret == false){
        getline(cin, find_item);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (inventory[i*5 + j] == find_item) {
                    current_weaponname = find_item;
                    current_weaponid = inventory_id[i*5 + j];
                    inventory[i*5 + j] = weapon_name;
                    inventory_id[i*5 + j] = item_id;
                    ret = true;
                    break;
                }
            }
            if(ret){
                break;
            }
        }
        if(ret == false){
            cout << "No such weapon in the inventory." << endl;
            cout << "Enter again: ";
        }
    }

}

int Inventory::get_wepId()
{
    return current_weaponid;
}