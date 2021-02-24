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

#include <iostream>
#include <cstring>
#include <cctype>

template <class Type>
class device
{
    public:
        device();
        //device(const device &);
        virtual ~device();

        //Virtual functions
        virtual int add(Type *to_add) = 0;
        virtual int remove() = 0;
        virtual void display() const = 0;
        virtual int search(Type *to_search) = 0;
    
    private:
        //int remove(device &to_remove);
        //void set_next(device *next);
        //device *get_next();
    
        //char *number, *capabilities;
        //device *next;

    protected:
    /*
	    char *number;
	    char *capabilities;
        char *device_type;
        device *next;
    */
};


#endif
