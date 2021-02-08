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
calendar::calendar() : a_week(nullptr)
{
}

//Calendar class default copy constructor
calendar::calendar(const calendar &to_copy)
{
    if (!this->a_week)
    {
        this->a_week = new week;
        this->a_week = nullptr;
    }
    this->a_week = to_copy.a_week;
}

//Calendar class default destructor
calendar::~calendar()
{
    if (this->a_week)
        delete this->a_week;
    this->a_week = nullptr;
}

//Calendar class insert function
bool calendar::insert(const calendar &to_insert)
{
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

//Week class functions
//Week class default constructor
week::week()
{
}

//Week class default copy constructor
week::week(const entry &to_copy)
{
}

//Week class default destructor
week::~week()
{
}

//Week class go to the previous node
week *&week::go_prev()
{
}

//Week class go to the next node
week *&week::go_next()
{
}

//Week class sets prev pointer
void week::set_prev(week *prev_ptr)
{
}

//Week class sets next pointer
void week::set_next(week *next_ptr)
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
void entry::add_next(entry *next_entry)
{
}