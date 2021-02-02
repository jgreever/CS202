#ifndef CALENDAR_HPP
#define CALENDAR_HPP
/** calendar.hpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains our base class, calendar.
 * 
 * The calendar class will be a base class pointer to our weekly calendar.
 * 
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class calendar
{
    public:
        //Base class default constructor
        calendar();

        //Base class VIRTUAL destructor
        virtual ~calendar();

    private:

    protected:

};

#endif
