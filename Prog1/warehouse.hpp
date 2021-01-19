#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>


//This is the "node" class for the warehouse class. It will keep track of
//adding items, removing items, and giving a total amount of items in that
//warehouse (local/national).
//
//There is a HUGE chance that this will change from a LLL to a Hash Table, as I
//think that may be easier for managing items and gives faster performance than
//the LLL would.
class inventory
{
    public:
        inventory();
        ~inventory();
        void add_item();
        void remove_item();
        void total_items();

    protected:
        int total_items;
        inventory *next;
};


//This is our warehouse class. It will be in charge of determining where the
//item should come from (local or national) distribution center and then help
//to determine if the package should go out via local or national if the item
//is found in the warehouses inventory.
class warehouse
{
    public:
        warehouse();
        ~warehouse();
        void check_inventory();
        void ship_local();
        void ship_national();
};

#endif