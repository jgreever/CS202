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

//static consts for weekdays = 7, weeks in a year = 52, and days in a year = 365
//these are just in case, and to make things a bit easier down the road, but
//they *could* be removed before turning in the final program.
static const int TOTAL_WEEKDAYS = 7;
static const int TOTAL_WEEKS = 52;
static const int TOTAL_DAYS = 365;

//Forward declarations
class week;
class entry;

//Calendar class. This is a pointer to the day class object. The day class
//object keeps track of the weeks for us.
//Since Calendar is the Base class, it also has a virtual destructor as to
//not cause issues deleting allocated memory later on, and is required for
//Derivation and RTTI to work properly.
class calendar
{
public:
    //Base class default constructor
    calendar();

    //Base class default copy constructor
    calendar(const calendar &to_copy);

    //Base class VIRTUAL destructor
    virtual ~calendar();

    //Self similar functions, VIRTUAL, arg1/arg2 are there just as
    //placeholders since this function is virtual.
    virtual bool add(char *arg1, char *arg2);
    virtual bool edit();
    virtual bool remove();
    virtual void display() const;

    //ADT only functions
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
    week *a_week;
};

//Week class. This class holds onto a LLL of entries that the
//user can add for a day to the week. The user can store an event,
//a project or a phone number to call back.
class week
{
public:
    //Default class constructor
    week();

    //Default copy constructor
    week(const week &);

    //Default copy constructor for an_entry
    week(const entry &);

    //Default class destructor
    ~week();

    //Node functions for the Day class
    week *&go_prev();
    week *&go_next();
    void set_prev(week *prev_ptr);
    void set_next(week *next_ptr);

private:
protected:
    //DLL: holds an entry object, as well as prev/next ptrs. for the DLL
    entry *entries;
    week *prev;
    week *next;
};

//Entry class. This class has a ptr to an entry (either an event,
//a phonecall, or a project), as well as a next ptr.
class entry
{
public:
    //Default class constructor
    entry();

    //Default class destructor
    ~entry();

    //Set/Get next ptr
    entry *&go_next();
    void add_next(entry *next_entry);

private:
protected:
    entry *an_entry;
    entry *head;
    entry *next;
};

#endif
