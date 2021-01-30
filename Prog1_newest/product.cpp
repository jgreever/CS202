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

//Inventory Node class copy constructor
inv_node::inv_node(const char *a_category) 
{
    if (this->cata_name)
    {
        delete []this->cata_name;
        cata_name = nullptr;
    }
    this->cata_name = new char[strlen(a_category) + 1];
    strcpy(this->cata_name, a_category);
};

//Inventory Copy Constructors
inv_node::inv_node(const category &to_copy) : category(to_copy) {};

//Get_Next, this bad boy will return the next ptr in the list.
inv_node *&inv_node::get_next()
{
    return *&next;
};

//Set_Next, this will take the the current next ptr and point
//it to the next node in the list
void inv_node::set_next(inv_node *to_set)
{
    next = to_set;
};

//Category Class Functions
//default constructor
category::category() : cata_name(nullptr), an_inventory(nullptr) {};

//constructor
category::category(const char *category_name)
{
    cata_name = new char[strlen(category_name) + 1];
    strcpy(cata_name, category_name);
};

//copy constructor
category::category(const category &to_copy) 
{
    cata_name = new char[strlen(to_copy.cata_name) + 1];
    strcpy(cata_name, to_copy.cata_name);
    an_inventory = new inventory(*to_copy.an_inventory);
};

//destructor for the category class
category::~category()
{
    if (cata_name)
        delete []cata_name;
    cata_name = nullptr;
    an_inventory = nullptr;
};

//Product class functions
//default constructor
product::product() : product_name(nullptr), product_location(0), total_product(0) {};

//constructor
product::product(const char *name, int location, int total)
{
    product_name = new char[strlen(name) + 1];
    strcpy(product_name, name);
    product_location = location;
    total_product = total;
};

product::product(const product &to_copy)
{
    product_location = to_copy.product_location;
    total_product = to_copy.total_product;
    product_name = new char[strlen(to_copy.product_name) + 1];
    strcpy(product_name, to_copy.product_name);
};

//product destructor
product::~product() {};

//Add a new product by passing in the name, location, and total amount
//of the item. Location values are 0 = local and 1 = national distribution
//center.
bool product::add_product(char *name, int location, int total)
{

    return true;
};

//Edit a product. We will pass in teh entire object and determine what
//needs to be edited: name, location, or amount of product.
bool product::edit_product(product &to_edit)
{

    return true;
};

//Remove a product. This will delete the entire product and null its
//data members before deallocating the memory.
bool product::remove_product(product &to_remove)
{

    return true;
};

