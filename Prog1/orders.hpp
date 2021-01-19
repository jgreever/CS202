#ifndef ORDERS_H
#define ORDERS_H

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
        int current_stage;
};

class node : public product
{
    public:
        node(const char *aname, char *anumber, int atracking);
        node(const product &);
    protected:
        //int current_stage; //I *don't* think I will need this here
        node *next;
};

//This is our orders class. It will be in charge of adding the needed
//information to the order for the product being purchased/shipped.
//This will add the customers name, address, and allow them to choose
//the shipping type/speed for the order. From there, this will go to 
//the package class to be processed and check inventory for the item.
class orders : public product
{
    public:
        orders();
        orders(const orders &);
        ~orders();
        
        //I know we shouldn't assume a person only has a first and
        //last name, but this is done for simplification reasons.
        //I tossed the idea of making one huge char *name that a
        //person could type virtualy anything in they wanted, but
        //figured that could lead to issues that I might not see
        //at this time.
        void add_name(char *first, char *last);

        //It seems like I could simplify the add_address function
        //by just having the user enter the street/city/state as
        //one entry as we did in lab, but I would rather have the
        //items separate from each other. It helps me to work with
        //dynamic memory and what not. :D
        void add_address(char *street, char *city, char *state, char *zip);
        void choose_shipping();

    protected:
        int order_id;
        char *customer_name;
        char *customer_address;
        char *shipping_type;
};


#endif