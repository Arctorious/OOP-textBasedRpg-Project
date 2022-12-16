#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>

using namespace std;

class Inventory
{
public:
    Inventory();
    ~Inventory();

    void discarded();
    void add_drop(string item_name, int item_id);
    void change_weapons();
    int get_wepId();
    bool disp_inven();
private:
    string* inventory;
    int* inventory_id;
    string current_weaponname;
    int current_weaponid;
};

#endif