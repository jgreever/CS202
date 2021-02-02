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
 * It manages an array of day pointers for the week. Each day object holds
 * an event as well as the next/previous pointers. The entry class holds onto
 * a next pointer.
 * 
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

//Forward declarations
class day;
class entry;

class calendar
{
    public:
        //Base class default constructor
        calendar();

        //Base class VIRTUAL destructor
        virtual ~calendar();

    private:

    protected:
        day *week;

};

class day
{
    public:
        //Default class constructor
        day();

        //Default class destructor
        ~day();

    private:

    protected:
        //DLL: holds an entry object and prev/next pointers
        entry *an_entry;
        day *prev;
        day *next;

};

class entry
{
    public:
        //Default class constructor
        entry();

        //Default class destructor
        ~entry();

    private:

    protected:
        entry *next;

};


#endif
