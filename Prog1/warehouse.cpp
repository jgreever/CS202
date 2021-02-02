#include "node.hpp"

/** warehouse.cpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * In this file, we have the functions related to the Warehouse and Inventory
 * classes. The warehouse is an ARR that contains a category node.  This keeps
 * track of the products from various categories that reside at both of the
 * distribution types (local and national). This should simplify tracking where
 * items are at and reduce un-needed traversal and wasted operations.
 * 
 */

//MAX size for our category array
const static int SIZE = 10;
//Inventory Class Functions
//default constructor
inventory::inventory() : a_product(nullptr), next(nullptr){};

//Default copy constructor
inventory::inventory(const inventory &to_copy) : a_product(to_copy.a_product), next(nullptr){};

//default destructor
inventory::~inventory()
{
    if (this->a_product)
        delete this->a_product;
    if (this->next)
        delete this->next;
    this->a_product = nullptr;
    this->next = nullptr;
};

//Get_Next: allows us to get the next node in the LLL
inventory *&inventory::get_next()
{
    return *&this->next;
};

//Set_Next: allows us to set the next node in the LLL
void inventory::set_next(inventory *to_set)
{
    this->next = to_set;
};

//Warehouse Class Functions
//default constructor
warehouse::warehouse(int SIZE)
{
    this->wh_inventory = nullptr;
    for (int idx = 0; idx < SIZE; ++idx)
        this->wh_inventory[idx] = nullptr;
};

//default destructor
warehouse::~warehouse()
{
    for (int idx = 0; idx < SIZE; ++idx)
    {
        delete this->wh_inventory[idx];
        this->wh_inventory[idx] = nullptr;
    }
    delete this->wh_inventory;
    this->wh_inventory = nullptr;
};

//Check inventory to ensure a product is in stock, if not
//it will reorder more products.
bool warehouse::check_inventory(char *name)
{

};

bool warehouse::edit_inventory(char *name, category *&an_inventory)
{

};

bool warehouse::set_shipping()
{
    if (product_location == 0)
        shipping_type = 0;
    if (product_location == 1)
        shipping_type = 1;
};

void warehouse::delete_arr(category *&an_arr)
{
    if (an_arr)
        delete []an_arr;
    an_arr = nullptr;
};

