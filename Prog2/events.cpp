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

events::events(char *arg1, char *arg2) : entry(arg1, arg2)
{
    if (this->temp1)
        delete[] this->temp1;
    if (this->temp2)
        delete[] this->temp2;
    this->temp1 = this->temp2 = nullptr;
    this->temp1 = new char[strlen(arg1) + 1];
    this->temp2 = new char[strlen(arg2) + 1];
    strcpy(this->temp1, arg1);
    strcpy(this->temp2, arg2);
    //cout << "\nEvents class copy constructor called (char, char)";
    //event_name = new char[strlen(arg1) + 1];
    //strcpy(event_name, arg1);
    //event_time = new char[strlen(arg2) + 1];
    //strcpy(event_time, arg2);
}

events::events(entry &to_copy) : entry(to_copy)
{
    *this = to_copy;
    //cout << "\nEvents class copy constructor called (obj)";
}

events::~events()
{
    if (this->temp1)
        delete[] this->temp1;
    if (this->temp2)
        delete[] this->temp2;
    this->temp1 = this->temp2 = nullptr;
    //cout << "\nEvents class destructor called";
    //if (event_name)
    //    delete[] event_name;
    //if (event_time)
    //    delete[] event_time;
    //event_name = event_time = nullptr;
}

bool events::add(entry *to_add)
{
    this->an_entry = to_add;
    return true;
}

bool events::add(char *an_event, char *time_for_event)
{
    //events *new_event = new events();
    //if (event_name)
    //    delete[] event_name;
    //if (event_time)
    //    delete[] event_time;
    if (this->temp1)
        delete[] this->temp1;
    if (this->temp2)
        delete[] this->temp2;
    this->temp1 = this->temp2 = nullptr;
    this->temp1 = new char[strlen(an_event) + 1];
    this->temp2 = new char[strlen(time_for_event) + 1];
    strcpy(this->temp1, an_event);
    strcpy(this->temp2, time_for_event);
    //event_name = new char[strlen(an_event) + 1];
    //event_time = new char[strlen(time_for_event) + 1];
    //strcpy(event_name, an_event);
    //strcpy(event_time, time_for_event);
    add(this);
    return true;
}

bool events::edit(entry &to_edit)
{
    return true;
}

bool events::remove(entry &to_remove)
{
    //delete[] event_name;
    //delete[] event_time;
    //event_name = event_time = nullptr;
    delete[] this->temp1;
    delete[] this->temp2;
    this->temp1 = this->temp2 = nullptr;
    return true;
}

void events::display() const
{
    cout << "\nEvent Name: " << this->temp1;
    cout << "\nEvent Time: " << this->temp2;
}
