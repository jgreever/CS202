#include "node.hpp"

/** product.cpp
 *
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * The product.cpp file contains the classes for its ADT (ARR), as well as the
 * classes within the product.hpp file. This keeps track of all categories for
 * items in the distribution centers (local or national).
 * 
 */

//Inventory Node class
inv_node::inv_node(const char *a_category) 
{

};

//Inventory Copy Constructors
inv_node::inv_node(const category &) 
{

};

/*
//Inventory Destructor
inv_node::~inv_node()
{
    if (next)
        delete next;
    next = nullptr;
};
*/

inv_node *&inv_node::get_next()
{
    return *&next;
};

void inv_node::set_next(inv_node *to_set)
{
    next = to_set;
};

//Category Class Functions
category::category() {};

category::category(const char *catagory_name)
{

};

category::category(const category &)
{

};

category::~category()
{

};
