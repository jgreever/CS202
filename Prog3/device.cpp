#include "methods.hpp"

device::device() : device_type(nullptr), next(nullptr) {}

device::device(const device &to_copy) : device_type(to_copy.device_type), next(to_copy.next) {}

device::~device()
{
    if(device_type)
        delete []device_type;
    device_type = nullptr;
}

void device::set_next(device *next)
{
    this->next = next;
}

device *&device::get_next()
{
    return next;
}

int device::add(device *to_add) { return 0; }

int device::remove(device &to_remove) { return 0; }

void device::display() const {}

int device::search(device *to_search) { return 0; }