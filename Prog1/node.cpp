#include "node.hpp"

/** node.cpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * This file contains the needed functions for a priority list as 
 * well as a tracking LLL (where it has been, where it is)
 * 
 * The ARR is within the warehouse.cpp/hpp files, as I didn't 
 * want to confuse myself with too many different types of ADTs
 * in one file and end up mis-calling them.
 * 
 */

//Default class constructor
priority::priority() : an_item(nullptr), next(nullptr) {};

//Default class destructor
priority::~priority()
{
    if (an_item)
        delete an_item;
    an_item = nullptr;
};

//Add_To_List: this allows us to add an item to the priority
//list to prevent un-needed traversal.
bool priority::add_to_list(product &to_add)
{
    an_item = new product(to_add);
    next = nullptr;
};

//Remove_From_List: removes an item from the priority list,
//i.e. you shipped the item, or it was not in stock.
bool priority::remove_from_list(char *product_name)
{

};

//Clear_List: of course, it clears the entire list of all items
//stored within (for when you have shipped all items)
bool priority::clear_list()
{

};

