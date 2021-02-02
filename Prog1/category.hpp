#include "inventory.hpp"

//Category class. This holds the category name and a LLL that holds each product
//and their related information.
class category : public inventory
{
public:
    category();
    category(const char *cate_name);
    category(const category &to_copy);
    ~category();

    bool add_category(char *category_name);
    void check_stock_wrapper(char *category_name, char *product_name);
    bool check_stock(inventory *next_node, char *product_name);
    bool edit_category(category *&to_edit, char *new_name);
    bool remove_category(category *&to_remove);

protected:
    char *cate_name;
    inventory *an_inventory;
};
