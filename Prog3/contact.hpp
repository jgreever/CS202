#ifndef CONTACT_HPP
#define CONTACT_HPP

/** contact.hpp
 *
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 *
 * This is the file for the Contact class. This is a fairly simple setup.
 *
 */ 

#include "methods.hpp"


class contact
{
    public:
        contact();
        contact(contact &to_copy);
        ~contact();

        int add(char *to_add, device *a_device);
        int edit(char *to_edit);
        int search(char *to_search);
        int remove(char *to_remove);
        int display() const;

    private:
        char *name;
        device *a_device;

    protected:
    /*
        char *name;
        device *a_device;
    */
};


#endif
