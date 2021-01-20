#ifndef WAREHOUSE_H
#define WAREHOUSE_H

/** warehouse.hpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * This file manages the warehouse class, inventory class and the product
 * class. This allows us to create a product, add it to inventory at a 
 * warehouse, edit the inventory, and help choose the shipping speed of 
 * the package based on the warehouse it is at (national/local).
 * 
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include "node.hpp"

//MAX categories a warehouse can have for products, to keep it simple.
static const int SIZE=10;

//Forward declaration for inventory class
class inventory;

//This is our warehouse class. It will be in charge of determining where the
//item should come from (local or national) distribution center and then help
//to determine if the package should go out via local or national if the item
//is found in the warehouses inventory.
class warehouse
{
    public:
        //Default constructor
        warehouse();

        //Default destructor
        ~warehouse();
        
        //This will allow the user to pass in a product name or number
        //and search to ensure the item is at a distribution center
        void check_inventory(char *name, char *product_num);

        //This is used so the user can input the product name/number, and a 
        //choice for what to do: 0 = add inventory, 1 = edit inventory
        void edit_inventory(char *name, char *product_num, int choice);

        //This allows us to flag the package for local shipping
        //This will most likely be merged with ship_national to make
        //it easier and less code
        void ship_local();

        //This allows us to flag the package for national shipping
        //This will most likely be merged with ship_local to make
        //it easier and less code
        void ship_national();

    protected:
        //This is our inventory pointer to our warehouse inventory
        //at the particular distribution center
        inventory *wh_inventory;
};

//Our product class will manage the physical item that is being shipped.
//It will hold the item name, product number, tracking ID, and the current
//stage of where it is in the chain, as well as the previous places it has
//been.
class product : public warehouse
{
    public:
        //This is our default constructor
        product();

        //This is a copy constructor
        product(const char *name, char *number);
        
        //This is another copy constructor
        product(const product &);
        
        //This is our default destructor
        ~product();
        
        //add_product will take in the product name and the product number
        //and create an object out of them.
        void add_product(char *name, char *number);

        //edit_product allows us to change the product name or number
        void edit_product(product &aproduct);

        //add_tracking allows us to create a tracking number for the package
        //and to track it's current place in the shipping chain. If void is
        //used in place of tracking, it will only update the current place
        //in the chain and leave tracking alone.
        void add_tracking(int tracking, int current);

        //In the check_inventory function, we will be passing in either the
        //product name, or the product number, then a 0 or 1, with 0 = name, 
        //and 1 = number.
        void check_inventory(char *check_product, int search_what);

    protected:
        char *item_name;
        char *product_number;
        char *tracking_id;
        int current_stage;
};

//The inventory class will manage the items in each warehouse via a categories.
//It will use an array of category names (max size of 100), that points to a 
//LLL that contains information about each product in that category such as
//the item name and item number.
class inventory : public product
{
    public:
        //Default constructor
        inventory();

        //Default destructor
        ~inventory();

        //This is our copy constructor for passing in char arguments and turning
        //them into an inventory object
        inventory(const char *aname, char *anumber);

        //This copy constructor allows us to copy an inventory object to another
        //inventory object without worrying about memory or pointer issues
        //(hopefully)
        inventory(const inventory &);

        //This function will allow a user to pass in a product name and number
        //so it can be searched for in the inventory. User may pass a '0' for
        //either argument to ignore that particular field, but must have one
        //of the arguments passed in that is non zero
        void search_inventory(char *aname, char *anumber);

        //This will allow us to pass in a product object and edit the info
        //about it (amount, name, product number)
        void edit_inventory(product &aproduct);

        //This function will allow us to enter a new product into the 
        //inventory system. The user will supply *BOTH* a name and a product 
        //number to the function
        void add_inventory(char *aname, char *anumber);

    protected:
        //the char *categories[SIZE] below will most likely be removed and 
        //changed to a constructor that creates 10 categories for the warehouse
        //and then points to a LLL for each item in that category.
        char **categories[SIZE];
        product *aproduct;
};

// class node : public inventory
// {
//     public:
//         //Default constructor
//         node();
//         //Default destructor
//         ~node();
//         //This sets our left pointer to point at the proper node
//         void set_left();
//         //This sets our right pointer to point at the proper node
//         void set_right();
//     protected:
//         inventory *an_inventory;
//         node *left;
//         node *right;
// };

//This is the "node" class for the warehouse class. It will keep track of
//adding items, removing items, and giving a total amount of items in that
//warehouse (local/national).
//
//There is a HUGE chance that this will change from a LLL to a Hash Table, as I
//think that may be easier for managing items and gives faster performance than
//the LLL would.
//inv_node = Inventory Node, as there is already an inventory class that is part
//of the orders.hpp/cpp files.
// class inv_node : public product
// {
//     public:
//         inv_node();
//         ~inv_node();
//         void add_item();
//         void remove_item();
//         void total_items();

//     protected:
//         int total_items;
//         inv_node *next;
// };


#endif