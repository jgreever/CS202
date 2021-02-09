/** calendar.cpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains our base class, calendar.
 * 
 */

#include "calendar.hpp"

//Calendar class functions
//Calendar class default constructor
calendar::calendar() : a_week(nullptr), head(nullptr), tail(nullptr), prev(nullptr), next(nullptr)
{
}

//Calendar class default copy constructor
calendar::calendar(const entry &to_copy)
{
    if (!this->a_week)
    {
        this->a_week = new entry;
        this->a_week = nullptr;
    }
    *this->a_week = to_copy;
}

//Calendar class default destructor
calendar::~calendar()
{
    if (this->a_week)
        delete this->a_week;
    this->a_week = nullptr;
    head = tail = prev = next = nullptr;
}

//Calendar class insert function
bool calendar::insert(const calendar &to_insert)
{
    this->a_week = new entry;
    this->a_week = to_insert.a_week;
}

//Calendar class removal function
bool calendar::remove(calendar *&to_remove)
{
}

//Calendar class display calendar function
void calendar::display_cal() const
{
}

//Calendar class remove all function
bool calendar::remove_all()
{
}

//Entry class functions
//Entry class default constructor
entry::entry()
{
}

//Entry class VIRTUAL default destructor
entry::~entry()
{
}

//Entry class add new entry function
bool entry::add(char *arg1, char *arg2)
{
}

//Entry class edit new entry function
bool entry::edit(entry &to_edit)
{
}

//Entry class remove entry function
bool entry::remove(entry *&to_remove)
{
}

//Entry class display entry function
void entry::display() const
{
}

//Entry class go to the next pointer
entry *&entry::go_next()
{
}

//Entry class add the next entry
void entry::set_next(entry *next_entry)
{
}