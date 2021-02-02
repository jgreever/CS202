#ifndef PHONECALLS_HPP
#define PHONECALLS_HPP
/** phonecalls.hpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains our derived class, phonecalls.
 * 
 */

#include "calendar.hpp"

class phonecalls : public entry
{
    public:
        //Derived class default constructor
        phonecalls();

        //Derived class default destructor
        ~phonecalls();

    private:

    protected:
        phonecalls *next;

};

#endif