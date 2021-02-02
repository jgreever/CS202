#include "node.hpp"

//Product class. This class contains an object that holds the products
//name, where the product is located (which distribution center), and
//the total amount of the product for inventory.
class product
{
public:
    product();
    product(const char *name, int a_category, int location, int total);
    product(const product &to_copy);
    ~product();

    bool add_product(char *name, int a_category, int location, int total);
    bool search_product(char *name);
    bool edit_product(product &to_edit);
    bool remove_product(product &to_remove);

protected:
    char *product_name;
    int product_category;

    //Warehouse checks this to see if it is 0 = local, 1 = national
    int product_location;

    //gets set by the warehouse, 0 = priority, 1 = express, 2 = overnight
    int shipping_type;
    int total_product;
};

