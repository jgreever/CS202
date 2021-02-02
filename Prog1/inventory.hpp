#include "product.hpp"

//This is the inventory class. It will hold a LLL of nodes that contain
//information about a product from a category held in an array.
class inventory : public product
{
public:
    inventory();
    inventory(const inventory &to_copy);
    ~inventory();

    inventory *&get_next();
    void set_next(inventory *to_set);

protected:
    product *a_product;
    inventory *next;
};

