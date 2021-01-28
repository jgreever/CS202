#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

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

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <time.h>
#include <cstdlib>

//MAX categories a warehouse can have for products.
static const int SIZE=10;

//Forward declarations
class inv_node;
class category;
class product;

//This is the inventory class. It will hold a LLL of nodes that contain 
//information about a product from a category held in an array.
class inventory
{
    public:
        inventory();
        inventory(const inventory &to_copy);
        inventory(const inventory &);
        ~inventory();

    protected:
        product *a_product;
        inv_node *next;
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
        bool check_inventory(char *name);
        bool edit_inventory(char *name);
        bool set_shipping();

    protected:
        category **wh_inventory;
};


#endif