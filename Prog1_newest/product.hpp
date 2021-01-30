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

//Category class. This holds the category name and a LLL that holds each product
//and their related information.
class category : public inventory
{
    public:
        category();
        category(const char *cata_name);
        category(const category &to_copy);
        ~category();

        bool add_category(char *cata_name);
        bool edit_category(category &to_edit);
        bool remove_category(category &to_remove);

    protected:
        char *cata_name;
        inventory *an_inventory;

};


//Product class. This class contains an object that holds the products
//name, where the product is located (which distribution center), and
//the total amount of the product for inventory.
class product
{
    public:
        product();
        product(const char *name, int location, int total);
        product(const product &to_copy);
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