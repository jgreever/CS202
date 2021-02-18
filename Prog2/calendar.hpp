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
class events;
class phonecalls;
class projects;
class node;

//Calendar class. This is a pointer to the day class object. The day class
//object keeps track of the weeks for us.
class calendar
{
public:
    //Class default constructor
    calendar();

    //Class default copy constructor
    calendar(calendar &to_copy);

    //Class destructor
    ~calendar();

    //ADT only functions
    calendar *&go_prev();
    calendar *&go_next();
    void set_prev(calendar *is_prev);
    void set_next(calendar *is_next);
    bool add(entry &to_insert);
    bool remove(entry &to_remove);
    void display();
    bool search(const entry *to_search);
    bool remove_all();

private:
    bool add(calendar *&to_add, entry &to_insert);

protected:
    void display(calendar *&to_display, entry *&disp);
    void remove_all(entry &to_remove);
    calendar *head;
    calendar *tail;
    calendar *prev;
    calendar *next;
    //node *an_entry;
    //int day_num;
    entry *day;
};

/*
//Node class for the calendar class. This is a DLL with a base
//class ptr to a LLL of things
class node : public calendar
{
public:
    node();
    node(entry &to_copy);
    //node(const calendar &to_copy);
    node *&go_next();
    node *&go_prev();
    void set_next(node *next_node);
    void set_prev(node *prev_node);

private:
protected:
    node *prev;
    int day_num;
    entry *a_day;
    node *next;
};
*/

//Entry class. This class has a ptr to an entry (either an event,
//a phonecall, or a project), as well as a next ptr.
class entry
{
public:
    //Default Base class constructor
    entry();

    //Default Base class copy constructor
    entry(char *arg1, char *arg2);

    //Default Base class copy constructor
    entry(entry &to_copy);

    //Default VIRTUAL Base class destructor
    virtual ~entry();

    //Self similar functions, VIRTUAL, TODO: arg1/arg2 are there just as
    //placeholders for the moment.
    virtual bool add(entry *to_add);
    virtual bool add(char *arg1, char *arg2);
    virtual bool edit(entry &to_edit);
    virtual bool remove(entry &to_remove);
    virtual void display() const;

    //Set/Get next ptr
    entry *&go_next();
    void set_next(entry *next_entry);

private:
protected:
    //events *anEvent;
    //phonecalls *aPhoneCall;
    //projects *aProject;
    char *temp1;
    char *temp2;
    entry *an_entry;
    entry *next;
};

#endif
