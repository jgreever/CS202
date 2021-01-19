/** product.hpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * ANCHOR //TODO: Add info about header
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include "warehouse.hpp"


class product
{
    public:
        product();
        product(const char *name, char *number, int tracking);
        product(const product &);
        ~product();
        void add_product();
        void edit_product();
        void add_tracking();
        void check_inventory();

    protected:
        char *item_name;
        char *product_number;
        int tracking_id;
};

class node : public product
{
    public:
        node(const char *aname, char *anumber, int atracking);
        node(const product &);
    protected:
        int current_stage;
        node *next;
};


#endif