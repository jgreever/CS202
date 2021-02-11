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
}

events::events(char *arg1, char *arg2) : event_name(arg1), event_time(arg2)
{
}

events::events(const events &to_copy) : entry(to_copy)
{
}

events::~events()
{
}

bool events::add(char *an_event, char *time_for_event)
{
}

bool events::edit(entry &to_edit)
{
}

bool events::remove(entry &to_remove)
{
}

void events::display() const
{
}
