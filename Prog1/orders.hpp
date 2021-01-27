#ifndef ORDERS_HPP
#define ORDERS_HPP

/** orders.hpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * This is our orders class. This class allows us to create a new
 * order for an item to ship to a user. It will allow us to add the
 * person ordering the products name, address, and shipping speed 
 * (express/standard/overnight), and the product name being purchased.
 * 
 */

#include "warehouse.hpp"


//This is our orders class. It will be in charge of adding the needed
//information to the order for the product being purchased/shipped.
//This will add the customers name, address, and allow them to choose
//the shipping type/speed for the order. From there, this will go to 
//the package class to be processed and check inventory for the item.
class orders
{
    public:
        //Default copy constructor
        orders();

        //Copy constructor for making a new copy of a order object
        orders(const orders &);

        //Our destructor
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
        char *product;
        char *customer_name;
        char *customer_address;
        char *shipping_type;
};


#endif