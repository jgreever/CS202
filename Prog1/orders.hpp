/* orders.hpp
 *
 * Justin Greever
 * CS202 - Program #1
 * 01/09/2020
 * 
 * //TODO: Add header comments
 */

#include <cstring>
#include <cctype>
#include <iostream>

class orders
{
    public:
        orders();
        ~orders();
        void new_order();
        void edit_order();
        void cancel_order();

    private:

    protected:
        int order_id;
        char *customer_name;
        char *customer_address;
        char *shipping_type;
};