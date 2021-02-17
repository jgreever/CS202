/** events.cpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains a derived class, events. 
 * 
 */

#include "events.hpp"

events::events() : event_name(nullptr), event_time(nullptr)
{
    //cout << "\nEvents class constructor called";
}

events::events(char *arg1, char *arg2) : event_name(arg1), event_time(arg2)
{
    //cout << "\nEvents class copy constructor called (char, char)";
    event_name = new char[strlen(arg1) + 1];
    strcpy(event_name, arg1);
    event_time = new char[strlen(arg2) + 1];
    strcpy(event_time, arg2);
}

events::events(entry &to_copy) : entry(to_copy)
{
    //cout << "\nEvents class copy constructor called (obj)";
}

events::~events()
{
    //cout << "\nEvents class destructor called";
    if (event_name)
        delete[] event_name;
    if (event_time)
        delete[] event_time;
    event_name = event_time = nullptr;
}

bool events::add(entry *&to_add)
{
    an_entry = to_add;
    return true;
}

bool events::add(char *an_event, char *time_for_event)
{
    //events *new_event = new events();
    if (event_name)
        delete[] event_name;
    if (event_time)
        delete[] event_time;

    event_name = new char[strlen(an_event) + 1];
    event_time = new char[strlen(time_for_event) + 1];
    strcpy(event_name, an_event);
    strcpy(event_time, time_for_event);
    return true;
}

bool events::edit(entry &to_edit)
{
    return true;
}

bool events::remove(entry &to_remove)
{
    delete[] event_name;
    delete[] event_time;
    event_name = event_time = nullptr;
    return true;
}

void events::display() const
{
    cout << "\nEvent Name: " << event_name;
    cout << "\nEvent Time: " << event_time;
}
