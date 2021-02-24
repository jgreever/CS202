#include "contact.hpp"

contact::contact() : name(nullptr), a_device(nullptr) {}

contact::contact(contact &to_copy) : name(to_copy.name), a_device(to_copy.a_device) {}

contact::~contact()
{
    if(name)
        delete []name;
    name = nullptr;
}

int contact::add(char *to_add, device *a_device) { return 0; }
