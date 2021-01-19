#ifndef ORDERS_H
#define ORDERS_H

#include "warehouse.hpp"

//MAX categories a warehouse can have for products, to keep it simple.
static const int SIZE=10;

//Our product class will manage the physical item that is being shipped.
//It will hold the item name, product number, tracking ID, and the current
//stage of where it is in the chain, as well as the previous places it has
//been.
class product
{
    public:
        //This is our default constructor
        product();

        //This is a copy constructor
        product(const char *name, char *number);
        
        //This is another copy constructor
        product(const product &);
        
        //This is our default destructor
        ~product();
        
        //add_product will take in the product name and the product number
        //and create an object out of them.
        void add_product(char *name, char *number);

        //edit_product allows us to change the product name or number
        void edit_product(product &aproduct);

        //add_tracking allows us to create a tracking number for the package
        //and to track it's current place in the shipping chain. If void is
        //used in place of tracking, it will only update the current place
        //in the chain and leave tracking alone.
        void add_tracking(int tracking, int current);

        //In the check_inventory function, we will be passing in either the
        //product name, or the product number, then a 0 or 1, with 0 = name, 
        //and 1 = number.
        void check_inventory(char *check_product, int search_what);

    protected:
        char *item_name;
        char *product_number;
        int tracking_id;
        int *current_stage;
};

//The inventory class will manage the items in each warehouse via a categories.
//It will use an array of category names (max size of 100), that points to a 
//LLL that contains information about each product in that category such as
//the item name and item number.
class inventory : public product
{
    public:
        inventory(const char *aname, char *anumber);
        inventory(const product &);
        void search_inventory(char *aname, char *anumber);
        void edit_inventory(product &aproduct);
        void add_inventory(char *aname, char *anumber);

    protected:
        //the char *categories[SIZE] below will most likely be removed and 
        //changed to a constructor that creates 10 categories for the warehouse
        //and then points to a LLL for each item in that category.
        char *categories[SIZE];
        product *aproduct;
        inventory *next;
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

        //This allows us to choose how we want the item shipped to us.
        //We can choose from Overnight, Express, or Standard. I'm 
        //thinking there may be a better way to tie in the shipping
        //in the near future before the code is fully turned in.
        void choose_shipping();

    protected:
        int order_id;
        char *customer_name;
        char *customer_address;
        char *shipping_type;
};


#endif