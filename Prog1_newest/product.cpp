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

//Default constructor
inv_node::inv_node() : next(nullptr) {};

//Inventory Node class copy constructor
inv_node::inv_node(const char *a_category)
{
    if (this->cata_name)
    {
        delete[] this->cata_name;
        this->cata_name = nullptr;
    }
    this->cata_name = new char[strlen(a_category) + 1];
    strcpy(this->cata_name, a_category);
};

//Inventory Copy Constructors
inv_node::inv_node(const category &to_copy) : category(to_copy){};

//Default destructor
inv_node::~inv_node()
{
    if (this->next)
        delete this->next;
    this->next = nullptr;
};

//Get_Next, this bad boy will return the next ptr in the list.
inv_node *&inv_node::get_next()
{
    return *&this->next;
};

//Set_Next, this will take the the current next ptr and point
//it to the next node in the list
void inv_node::set_next(inv_node *to_set)
{
    this->next = to_set;
};

//Category Class Functions
//default constructor
category::category() : cata_name(nullptr), an_inventory(nullptr){};

//constructor
category::category(const char *category_name)
{
    this->cata_name = new char[strlen(category_name) + 1];
    strcpy(this->cata_name, category_name);
};

//copy constructor
category::category(const category &to_copy)
{
    this->cata_name = new char[strlen(to_copy.cata_name) + 1];
    strcpy(this->cata_name, to_copy.cata_name);
    this->an_inventory = new inventory(*to_copy.an_inventory);
};

//destructor for the category class
category::~category()
{
    if (this->cata_name)
        delete[] this->cata_name;
    this->cata_name = nullptr;
    this->an_inventory = nullptr;
};

bool category::add_category(char *category_name)
{
    if (!this->cata_name)
    {
        this->cata_name = new char[strlen(category_name) + 1];
        strcpy(this->cata_name, category_name);
        return true;
    }
    else
        return false;
};

//Edit_Category, allows a user to edit the name of the category
bool category::edit_category(category *&to_edit, char *new_name)
{
    if (!to_edit)
        return false;
    else
    {
        to_edit->cata_name = new char[strlen(new_name) + 1];
        strcpy(to_edit->cata_name, new_name);
    }
    return true;
};

//Remove_Category, this will remove an entire category and all
//the products contained within. This would be used in the event
//items are being moved from one facility to another, or a certain
//category of items is restricted (unable to sell, maybe they lost
//their liquor license or something).
bool category::remove_category(category *&to_remove)
{
    if (!to_remove)
        return false;
    else
    {
        delete[] to_remove->cata_name;
        to_remove->cata_name = nullptr;
    }
    return true;
};

//Product class functions
//default constructor
product::product() : product_name(nullptr), product_category(0), product_location(0), total_product(0){};

//constructor
product::product(const char *name, int a_category, int location, int total)
{
    this->product_name = new char[strlen(name) + 1];
    strcpy(this->product_name, name);
    this->product_category = a_category;
    this->product_location = location;
    this->total_product = total;
};

product::product(const product &to_copy)
{
    this->product_category = to_copy.product_category;
    this->product_location = to_copy.product_location;
    this->total_product = to_copy.total_product;
    this->product_name = new char[strlen(to_copy.product_name) + 1];
    strcpy(this->product_name, to_copy.product_name);
};

//product destructor
product::~product()
{
    if (this->product_name)
        delete[] this->product_name;
    this->product_name = nullptr;
    this->product_category = this->product_location = this->total_product = 0;
};

//Add a new product by passing in the name, location, and total amount
//of the item. Location values are 0 = local and 1 = national distribution
//center.
bool product::add_product(char *name, int a_category, int location, int total)
{
    if (!product_name)
    {
        this->product_name = new char[strlen(name) + 1];
        strcpy(this->product_name, name);
        this->product_category = a_category;
        this->product_location = location;
        this->total_product = total;
        return true;
    }
    else
        return false;
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
