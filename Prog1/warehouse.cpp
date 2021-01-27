/** warehouse.cpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * The warehouse.cpp file contains the functions for the following classes:
 * -- class warehouse //Base class
 * -- class product //Derived from warehouse
 * -- class inventory //Derived from product
 * -- class inv_node //Derived from inventory
 * 
 */

#include "warehouse.hpp"

warehouse::warehouse() : wh_inventory(nullptr)
{

}

warehouse::~warehouse()
{
    if(wh_inventory)
        delete wh_inventory;
    wh_inventory = nullptr;
}

void warehouse::check_inventory(char *name, char *product_num)
{

}

void warehouse::edit_inventory(char *name, char *product_num, int choice)
{

}

void warehouse::ship_local()
{

}

void warehouse::ship_national()
{

}

product::product()
{

}

product::product(const char *name, char *number)
{

}

product::~product()
{

}

void product::add_product(char *name, char *number)
{

}

void product::edit_product(product &aproduct)
{

}

void product::add_tracking(int tracking, int current)
{

}

void product::check_inventory(char *check_product, int search_what)
{

}

inventory::inventory()
{

}

inventory::inventory(const char *aname, const char *anumber)
{

}

inventory::~inventory()
{

}

void inventory::search_inventory(char *aname, char *anumber)
{

}

void inventory::edit_inventory(product &aproduct)
{

}

void inventory::add_inventory(char *aname, char *anumber)
{

}

inv_node::inv_node() : t_items(0), next(nullptr)
{

}

inv_node::inv_node(const inv_node &to_copy)
{

}

inv_node::inv_node(const inv_node &to_copy, inv_node *new_next)
{
    t_items = to_copy.t_items;
    next = new_next;
}

inv_node::~inv_node()
{
    inv_node *temp;
}

inv_node *&inv_node::goNext()
{
    return next;
}

void inv_node::setNext(inv_node *&new_next)
{
    if (!new_next) next = nullptr;
    else
        next = new_next->next;
}

void inv_node::setData(int to_set)
{
    t_items = to_set;
}

int inv_node::getData() const
{
    return t_items;
}