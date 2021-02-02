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


//Category Class Functions
//default constructor
category::category() : cate_name(nullptr), an_inventory(nullptr){};

//constructor
category::category(const char *category_name)
{
    this->cate_name = new char[strlen(category_name) + 1];
    strcpy(this->cate_name, category_name);
};

//copy constructor
category::category(const category &to_copy)
{
    this->cate_name = new char[strlen(to_copy.cate_name) + 1];
    strcpy(this->cate_name, to_copy.cate_name);
    this->an_inventory = new inventory(*to_copy.an_inventory);
};

//destructor for the category class
category::~category()
{
    if (this->cate_name)
        delete[] this->cate_name;
    this->cate_name = nullptr;
    this->an_inventory = nullptr;
};

bool category::add_category(char *category_name)
{
    if (!this->cate_name)
    {
        this->cate_name = new char[strlen(category_name) + 1];
        strcpy(this->cate_name, category_name);
        return true;
    }
    else
        return false;
};

//Wrapper to support check_stock function
void category::check_stock_wrapper(char *category_name, char *product_name)
{
    if (!this->cate_name) return;
    if (strcmp(this->cate_name, category_name) == 0)
        check_stock(an_inventory, product_name);
    else
        check_stock(get_next(), product_name);

};

//Check_Stock: this allows us to check if an item is in stock, and if
//so, where it is in stock at. If not in stock, check reorder process.
bool category::check_stock(inventory *an_inventory, char *product_name)
{
    return true;
};

//Edit_Category, allows a user to edit the name of the category
bool category::edit_category(category *&to_edit, char *new_name)
{
    if (!to_edit)
        return false;
    else
    {
        to_edit->cate_name = new char[strlen(new_name) + 1];
        strcpy(to_edit->cate_name, new_name);
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
        delete[] to_remove->cate_name;
        to_remove->cate_name = nullptr;
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

//Search_Product: This allows us to search if a product is in stock or not. If 
//it is not in stock, check if reorder is needed.
bool product::search_product(char *name)
{
    int found = strcmp(this->product_name, name);
    if (found == 0)
        return true;
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

