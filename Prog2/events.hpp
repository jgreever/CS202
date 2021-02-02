#ifndef EVENTS_HPP
#define EVENTS_HPP
/** events.hpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains our derived class, events.
 * 
 */

#include "calendar.hpp"

class events : public entry
{
    public:
        //Derived class default constructor
        events();

        //Derived class default destructor
        ~events();

    private:

    protected:
        events *next;

};

#endif