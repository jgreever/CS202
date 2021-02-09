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
 * I am playing with the idea of making the Calendar a pointer to an array of
 * calendars that have a size of 52, as there are 52 weeks in the year. I also
 * pondered making the week ptr do the same in the week class.
 * 
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <exception>
using namespace std;

//Forward declarations
class entry;

//Calendar class. This is a pointer to the day class object. The day class
//object keeps track of the weeks for us.
class calendar
{
public:
    //Class default constructor
    calendar();

    //Class default copy constructor
    calendar(const entry &to_copy);

    //Class destructor
    ~calendar();

    //ADT only functions
    calendar *&go_next();
    calendar *&go_prev();
    bool set_next(calendar *next_node);
    bool set_prev(calendar *prev_node);
    bool insert(const calendar &to_insert);
    bool remove(calendar *&to_remove);
    void display_cal() const;
    bool retrieve(const calendar &to_retrieve);
    bool remove_all();

    ;

private:
protected:
    void display_cal(calendar *to_display);
    void remove_all(calendar *&to_remove);
    entry *a_week;
    calendar *head;
    calendar *tail;
    calendar *prev;
    calendar *next;
};

//Entry class. This class has a ptr to an entry (either an event,
//a phonecall, or a project), as well as a next ptr.
class entry
{
public:
    //Default Base class constructor
    entry();

    //Default VIRTUAL Base class destructor
    virtual ~entry();

    //Self similar functions, VIRTUAL, TODO: arg1/arg2 are there just as
    //placeholders for the moment.
    virtual bool add(char *arg1, char *arg2);
    virtual bool edit(entry &to_edit);
    virtual bool remove(entry *&to_remove);
    virtual void display() const;

    //Set/Get next ptr
    entry *&go_next();
    void set_next(entry *next_entry);

private:
protected:
    entry *an_entry;
    entry *next;
};

#endif
