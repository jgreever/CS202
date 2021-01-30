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


//Inventory Class Functions
//default constructor
inventory::inventory() {};

//Default copy constructor
inventory::inventory(const inventory &to_copy) : a_product(to_copy.a_product),  next(nullptr) {};

//default destructor
inventory::~inventory() {};


//Warehouse Class Functions
//default constructor
warehouse::warehouse(int SIZE)
{
    wh_inventory = nullptr;

};

//default destructor
warehouse::~warehouse() 
{
    for (int idx = 0; idx < SIZE; ++idx)
    {
        
    }
};