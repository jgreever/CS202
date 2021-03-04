/** device.cpp
 * 
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 * 
 * This file contains the Device class. This is the base class
 * for our 3 derrived classes: Phone, Pager, and VoIP.
 * 
 * This class holds our data for our derrived classes. It holds
 * a device *next, but this will most likely be removed and done
 * differently.
 * 
 */

#include "methods.hpp"

// Abstract class constructor
device::device() : number(nullptr), capabilities(nullptr), next(nullptr){} 

 // Abstract class destructor
device::~device() {
        if (number)
            delete []number;
        if (capabilities)
            delete[] capabilities;
        if (next)
            delete next;
        number = capabilities = nullptr;
        next = nullptr;
}

int device::add()
{
    // Pure virtual function    
    return 1;
}

int device::remove()
{
    // Pure virtual function
    return 1;
}

void device::display() const
{
    // Pure virtual function
}
