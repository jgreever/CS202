#include "methods.hpp"

phone::phone() : number(nullptr), capabilities(nullptr) {}

phone::phone(const phone &to_copy) : number(to_copy.number), capabilities(to_copy.capabilities) {}

phone::~phone()
{
    if(number)
        delete []number;
    number = nullptr;
    if(capabilities)
        delete []capabilities;
    capabilities = nullptr;
}

int phone::add(device *to_add) { return 0; }

int phone::remove(device &to_remove) { return 0; }

void phone::display() const {}

int phone::search(device *to_search) { return 0; }

