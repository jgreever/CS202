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

class address
{
public:
    address();
    address(char *street, char *zip);
    address(const address &to_add);
    ~address();
    void change_address(char *new_street, char *new_zip);
    void copy_address(const address &to_copy);
    bool check_zip(const char *zip_to_compare) const;
    void read();
    void display() const;

protected:
    char *street;
    char *zip;
};

class name
{
public:
    name();
    name(char *name);
    name(const name &to_add);
    ~name();
    void add_name(const name &a_name);

protected:
    char *a_name;
};

class orders : public name
{
public:
    orders();
    orders(char *name, char *address, char *shipping);
    void new_order(char *name, char *address, char *shipping);
    void edit_order();
    void cancel_order();

protected:
    address an_address;
};
