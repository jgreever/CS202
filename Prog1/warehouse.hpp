#include <cctype>
#include <iostream>
#include <cstring>
#include "category.hpp"

using namespace std;


//This is our warehouse class. It will be in charge of determining where the
//item should come from (local or national) distribution center and then help
//to determine if the package should go out via local or national if the item
//is found in the warehouses inventory.
class warehouse : public category
{
public:
    warehouse(int SIZE);
    ~warehouse();
    bool check_inventory(char *name);
    bool edit_inventory(char *name, category *&an_inventory);
    bool set_shipping();

protected:
    //recursive function to delete our ARR and release any dynamically
    //allocated memory in the process
    void delete_arr(category *&an_arr);
    category **wh_inventory;
};
