/** product.cpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * ANCHOR //TODO: Add info about the programs use
 */

#include "product.hpp"

//default constructor
product::product()
{
    item_name = nullptr;
    product_number = nullptr;
    tracking_id = 0;
};

//default copy constructor
product::product(char *name, char *number, int tracking) : item_name(name), product_number(number), tracking_id(tracking)
{
    //Nothing to do here
};

//default destructor
product::~product()
{
    if (item_name)
    {
        delete []item_name;
        item_name = nullptr;
    }
    if (product_number)
    {
        delete []product_number;
        product_number = nullptr;
    }
    tracking_id = 0;
};

void product::add_product()
{

};

void product::edit_product()
{

};

void product::add_tracking()
{

};
