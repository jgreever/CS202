#ifndef PRODUCT_HPP
#define PRODUCT_HPP

 /** product.hpp
  *
  * Justin Greever
  * CS202 - Program 1
  * 01/09/2021
  *
  * Our product class will manage the physical item that is being shipped.
  * It will hold the item name, product number, tracking ID, and the current
  * stage of where it is in the chain, as well as the previous places it has
  * been.
  *
  */

#include "warehouse.hpp"

class category
{
    public:
        category();
        category(const char *cata_name);
        category(const category &);
        //category(const category &);
        ~category();

        bool add_category(char *cata_name);
        bool edit_category(category &to_edit);
        bool remove_category(category &to_remove);

    protected:
        char *cata_name;
        inventory *an_inventory;

};

class product
{
    public:
        product();
        product(const char *name, int location, int total);
        product(const product &);
        ~product();

        bool add_product(char *name, int location, int total);
        bool edit_product(product &to_edit);
        bool remove_product(product &to_remove);

    protected:
        char *product_name;
        int product_location;
        int total_product;

};


#endif