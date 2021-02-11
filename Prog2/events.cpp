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

events::events() : event_name(nullptr), event_time(nullptr) {}

events::events(char *arg1, char *arg2) : event_name(arg1), event_time(arg2)
{
    this->event_name = new char[strlen(arg1) + 1];
    strcpy(this->event_name, arg1);
    this->event_time = new char[strlen(arg2) + 1];
    strcpy(this->event_time, arg2);
}

events::events(const events &to_copy) : entry(to_copy)
{
    this->an_entry = new events(to_copy);
}

events::~events()
{
    if (event_name)
        delete []event_name;
    if (event_time)
        delete[] event_time;
    event_name = event_time = nullptr;
}

bool events::add(char *an_event, char *time_for_event)
{
    this->an_entry = new events(an_event, time_for_event);
    set_next(this);
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
}

void events::display() const
{
    cout << "\nEvent Name: " << this->event_name;
    cout << "\nEvent Time: " << this->event_time;
}
