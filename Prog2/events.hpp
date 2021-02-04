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
 * The events class holds onto the name of the event, as well as the event
 * time. This can be thought of as the simple, default calendar entry. It
 * may contain another piece of data before finishing the program. The class
 * may have a LLL added that holds onto information about the event: address, 
 * phone number, etc. 
 * 
 */

#include "calendar.hpp"

class events : public entry
{
public:
    //Derived class default constructor
    events();

    //Derived class default copy constructor
    events(const events &to_copy);

    //Derived class default destructor
    ~events();

    //Self similar functions
    bool add(char *an_event, char *time_for_event);
    bool edit();
    bool remove();
    void display() const;

private:
protected:
    char *event_name;
    char *event_time;
};

#endif