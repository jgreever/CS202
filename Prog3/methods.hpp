#ifndef METHODS_HPP
#define METHODS_HPP

/** methods.hpp
 *
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 *
 * This file holds the three derived classes: phone, pager, voip
 * Each class holds the same data: number, capabilities
 * Number can be be a few types of things. It can be in the standard
 * telephone number style (555-555-1212), or as a VoIP number similar
 * to phone_extension@ip.address (101@127.0.0.1) or user@domain.name
 *
 * I am going to work on, and hopefully by the time I turn this in, 
 * have the base class, Device, be pure virtual. If that can't happen
 * for some reason, I plan on keeping it simple and using its data 
 * members to hold the information, much like I did in program 2.
 *
 */
 
#include "device.hpp"

class phone : public device
{
    public:
        phone();
        phone(const phone &);
        ~phone();
        int add(device *to_add);
        int remove();
        void display() const;
        int search(device *to_search);

    private:
        char *number, *capabilities;
};

class pager : public device
{
    public:
        pager();
        pager(const pager &);
        ~pager();

        int add(device *to_add);
        int remove();
        void display() const;
        int search(device *to_search);

    private:
        char *number, *capabilities;
};

class voip : public device
{
    public:
        voip();
        voip(const voip &);
        ~voip();

        int add(device *to_add);
        int remove();
        void display() const;
        int search(device *to_search);

    private:
        char *number, *capabilities;
};


#endif
