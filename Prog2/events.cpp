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
    this->event_name = new char[strlen(arg1) + 1];
    strcpy(this->event_name, arg1);
    this->event_time = new char[strlen(arg2) + 1];
    strcpy(this->event_time, arg2);
}

events::events(const entry &to_copy) : entry(to_copy)
{
    //cout << "\nEvents class copy constructor called (obj)";
}

events::~events()
{
    //cout << "\nEvents class destructor called";
    if (this->event_name)
        delete[] this->event_name;
    if (this->event_time)
        delete[] this->event_time;
    this->event_name = this->event_time = nullptr;
}

entry *events::clone() const
{
    return new events(static_cast<entry const &>(*this));
}

bool events::add(entry *to_add)
{
    this->an_entry = to_add;
    return true;
}

bool events::add(char *an_event, char *time_for_event)
{
    //events *new_event = new events();
    this->event_name = new char[strlen(an_event) + 1];
    this->event_time = new char[strlen(time_for_event) + 1];
    strcpy(this->event_name, an_event);
    strcpy(this->event_time, time_for_event);
    entry::set_next(this);
    return true;
}

bool events::edit(entry &to_edit)
{
    return true;
}

bool events::remove(entry &to_remove)
{
    delete[] this->event_name;
    delete[] this->event_time;
    this->event_name = this->event_time = nullptr;
    return true;
}

void events::display() const
{
    cout << "\nEvent Name: " << event_name;
    cout << "\nEvent Time: " << event_time;
}
