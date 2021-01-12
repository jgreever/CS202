#ifndef PRODUCT_H
#define PRODUCT_H

#include "warehouse.hpp"


class product
{
    public:
        product();
        product(char *name, char *number, int tracking);
        ~product();
        void add_product();
        void edit_product();
        void add_tracking();

    private:
    
    protected:
        char *item_name;
        char *product_number;
        int tracking_id;
};


#endif