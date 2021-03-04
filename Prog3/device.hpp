#ifndef DEVICE_HPP
#define DEVICE_HPP

/** device.hpp
 *
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 *
 * This file holds the Device class. This is the base class. I want to make
 * this pure virtual, but in the event that I cannot, it will be fairly simple
 * and allow storage of the derived class information.
 *
 * A device object holds onto the device type, contact number, and capabilities
 * of the device/method.
 *
 */

#include "bst.hpp"

//Attempting to make this a pure virtual function/abstract class
class device
{
    public:
        device();
        virtual ~device();

        //Virtual functions
        virtual int add() = 0;
        virtual int remove() = 0;
        virtual void display() const = 0;
        //virtual int search(device *to_search) = 0;

    private:
        char *number, *capabilities;
        device *next;
};


#endif