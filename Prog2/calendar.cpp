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
    cout << "\nCalendar class constructor called";
}

//Calendar class default copy constructor
calendar::calendar(const calendar &to_copy) : prev(to_copy.prev), head(to_copy.head), day(to_copy.day), next(to_copy.next)
{
    cout << "\nCalendar class copy constructor called";
    *this = to_copy;
}

//Calendar class default destructor
calendar::~calendar()
{
    cout << "\nCalendar class destructor called";
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
    return next;
}

//Calendar class go_prev function
calendar *&calendar::go_prev()
{
    return prev;
}

//Calendar class set_next function
bool calendar::set_next(calendar *&next_node)
{
    this->next = next_node;
    next_node->prev = this;
    return true;
}

//Calendar class set_prev function
bool calendar::set_prev(calendar *&prev_node)
{
    this->prev = prev_node;
    prev_node->next = this;
    return true;
}

//Calendar class add function
bool calendar::add(const entry &to_insert)
{
    calendar *head = new calendar;
    if (!head) //no list, create a new one
    {
        head = new calendar;
        head->day = new entry(to_insert);
        head->set_next(head);
        head->prev = nullptr;
        return true;
    }
    else if (!head->next) //only one node, create a new one and link them
    {
        calendar *temp = new calendar;
        temp->day = new entry(to_insert);
        temp->set_prev(head);
        head->set_next(temp);

        return true;
    }
    else
    {
        calendar *temp = new calendar;
        calendar *curr = new calendar;
        temp->day = new entry(to_insert);
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
bool calendar::remove(calendar &to_remove)
{
    if (to_remove.next)
    {
        to_remove.prev->next = to_remove.next;
        to_remove.next->prev = to_remove.prev;
        delete this;
        this->next = this->prev = nullptr;
    }
}

//Calendar class display calendar function
void calendar::display() const
{
    if (!head)
        return;
    head->day->display();
    head->next->display();
}

//Calendar class search function
bool search(const calendar *to_search)
{
    return true;
}

//Calendar class remove all function
bool calendar::remove_all()
{
    return true;
}

//Entry class functions
//Entry class default constructor
entry::entry() : an_entry(nullptr), next(nullptr)
{
    cout << "\nEntry class constructor called";
}

//Entry class default copy constructor
entry::entry(const entry &to_copy) : an_entry(to_copy.an_entry)
{
    cout << "\nEntry class copy constructor called";
    *this = to_copy;
}

//Entry class VIRTUAL default destructor
entry::~entry()
{
    cout << "\nEntry class destructor called";
    if (this->an_entry)
    {
        delete an_entry;
        an_entry = nullptr;
    }
    next = nullptr;
}

//Entry class add new entry function
bool entry::add(entry *to_add)
{
    *this = *to_add;
    return true;
}

//Entry class add new entry function
bool entry::add(char *arg1, char *arg2)
{
    return true;
}

//Entry class edit new entry function
bool entry::edit(entry &to_edit)
{
    return true;
}

//Entry class remove entry function
bool entry::remove(entry &to_remove)
{
    return true;
}

//Entry class display entry function
void entry::display() const
{
    this->an_entry->display();
}

//Entry class go to the next pointer
entry *&entry::go_next()
{
    return next;
}

//Entry class add the next entry
void entry::set_next(entry *&next_entry)
{
    this->next = next_entry;
}