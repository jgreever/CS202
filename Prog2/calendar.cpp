/** calendar.cpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains our base class, calendar.
 * 
 */

#include "projects.hpp"

//Calendar class functions
//Calendar class default constructor
calendar::calendar() : prev(nullptr), head(nullptr), day(nullptr), next(nullptr)
{
}

//Calendar class default copy constructor
calendar::calendar(const calendar &to_copy) : prev(to_copy.prev), head(to_copy.head), day(to_copy.day), next(to_copy.next)
{
}

//Calendar class default destructor
calendar::~calendar()
{
    if (this->day)
        delete this->day;
    if (this->head)
        delete this->head;
    this->head = nullptr;
    this->prev = this->next = nullptr;
}

//Calendar class go_next function
calendar *&calendar::go_next()
{
    return *&next;
}

//Calendar class go_prev function
calendar *&calendar::go_prev()
{
    return *&prev;
}

//Calendar class set_next function
bool calendar::set_next(calendar *next_node)
{
    this->next = next_node;
    next_node->prev = this;
    return true;
}

//Calendar class set_prev function
bool calendar::set_prev(calendar *prev_node)
{
    this->prev = prev_node;
    prev_node->next = this;
}

//Calendar class add function
bool calendar::add(const entry &to_insert)
{
    if (!head) //no list, create a new one
    {
        head = new calendar;
        head->set_next(head);
        head->prev = nullptr;
        return true;
    }
    else if (!head->next) //only one node, create a new one and link them
    {
        calendar *temp = new calendar;
        set_prev(head);
        set_next(head);

        return true;
    }
    else
    {
        calendar *temp = new calendar;
        calendar *curr = new calendar;
        curr = head;
        if (!curr->next)
        {
            curr->next = temp;
            temp->next = curr;
            return true;
        }
        else
            curr = curr->next;
    }
    return false;
}

//Calendar class remove function
bool calendar::remove(calendar &to_remove) {}

//Calendar class display calendar function
void calendar::display() const {}

//Calendar class search function
bool search(const calendar &to_search) {}

//Calendar class remove all function
bool calendar::remove_all() {}

//Entry class functions
//Entry class default constructor
entry::entry() : an_entry(nullptr), next(nullptr) {}

//Entry class default copy constructor
entry::entry(const entry &to_copy) : an_entry(to_copy.an_entry) {}

//Entry class VIRTUAL default destructor
entry::~entry()
{
    if (this->an_entry)
    {
        delete an_entry;
        an_entry = nullptr;
    }
    next = nullptr;
}

//Entry class add new entry function
bool entry::add(char *arg1, char *arg2) {}

//Entry class edit new entry function
bool entry::edit(entry &to_edit) {}

//Entry class remove entry function
bool entry::remove(entry &to_remove) {}

//Entry class display entry function
void entry::display() const {}

//Entry class go to the next pointer
entry *&entry::go_next()
{
    return *&next;
}

//Entry class add the next entry
void entry::set_next(entry *next_entry)
{
    this->next = next_entry;
}