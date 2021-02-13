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
calendar::calendar() : head(nullptr), tail(nullptr), day_num(0), day(nullptr)
{
    //cout << "\nCalendar class constructor called";
}

//Calendar class default copy constructor
calendar::calendar(entry &to_copy) : day(nullptr)
{
    day->add(&to_copy);
}

//Calendar class default copy constructor
calendar::calendar(calendar &to_copy) : head(to_copy.head), tail(to_copy.tail), day_num(to_copy.day_num), day(to_copy.day)
{
    //cout << "\nCalendar class copy constructor called";
}

//Calendar class default destructor
calendar::~calendar()
{
    //cout << "\nCalendar class destructor called";
    if (this->head)
    {
        delete this->head;
        this->head = nullptr;
    }
}

//Calendar class add function
bool calendar::add(entry *to_insert)
{
    if (!head) //no list, create a new one
    {
        head = new node;
        tail = new node;
        head->day = new entry;
        head->set_prev(nullptr);
        head->day->add(to_insert);
        head->set_next(tail);
        tail->set_prev(head);
        tail->set_next(nullptr);
        return true;
    }
    else if (!head->go_next()) //only one node, create a new one and link them
    {
        node *temp = new node;
        temp->day = new entry;
        temp->day->add(to_insert);
        temp->set_prev(head);
        head->set_next(temp);
        temp->set_next(tail);
        tail->set_prev(temp);
        tail->set_next(nullptr);
        return true;
    }
    else
    {
        node *temp = new node;
        node *curr = head;
        temp->day = new entry;
        temp->day->add(to_insert);
        if (tail)
        {
            curr = tail->go_prev();
            curr->set_next(temp);
            temp->set_prev(curr);
            temp->set_next(tail);
            tail->set_prev(temp);
            tail->set_next(nullptr);
            return true;
        }
    }
    return false;
}

//Calendar class remove function
bool calendar::remove(entry &to_remove)
{
    return true;
}

//Calendar class display calendar wrapper function
void calendar::display() const
{
    if (!head)
        return;
    return display(head);
}

//Calendar class display calendar function
void calendar::display(node *disp) const
{
    if (!disp)
        return;
    day->display();
    if (day->go_next())
    {
        day->go_next();
        day->display();
    }
    else
        return;
}

//Calendar class search function
bool calendar::search(const entry *to_search)
{
    return true;
}

//Calendar class remove all function
bool calendar::remove_all()
{
    return true;
}

//Node class functions
//node class default constructor
node::node() : prev(nullptr), next(nullptr)
{
    //cout << "\nNode class constructor called";
}

//node class copy constructor
node::node(entry &to_copy) : calendar(to_copy)
{
    //cout << "\nNode class copy constructor called (obj)";
}

//node class go_next function
node *&node::go_next()
{
    return next;
}

//node class go_prev function
node *&node::go_prev()
{
    return prev;
}

//node class set_next function
void node::set_next(node *next_node)
{
    next = next_node;
    //next_node->prev = this;
}

//node class set_prev function
void node::set_prev(node *prev_node)
{
    prev = prev_node;
    //prev_node->next = this;
}

//Entry class functions
//Entry class default constructor
entry::entry() : temp1(nullptr), temp2(nullptr), an_entry(nullptr), next(nullptr)
{
    //cout << "\nEntry class constructor called";
}

//entry class default copy constructor
entry::entry(char *arg1, char *arg2) : temp1(nullptr), temp2(nullptr)
{
    temp1 = new char[strlen(arg1) + 1];
    temp2 = new char[strlen(arg2) + 1];
    strcpy(temp1, arg1);
    strcpy(temp2, arg2);
}

//Entry class default copy constructor (obj)
entry::entry(const entry &to_copy) : an_entry(to_copy.an_entry), next(to_copy.next)
{
    //cout << "\nEntry class copy constructor called";
}

//Entry class VIRTUAL default destructor
entry::~entry()
{
    //cout << "\nEntry class destructor called";
    if (this->an_entry)
    {
        delete an_entry;
        an_entry = nullptr;
    }
    next = nullptr;
}

entry *entry::clone() const
{
    return new entry(*this);
    //return new entry(static_cast<entry const &>(*this));
}

//Entry class add new entry function
bool entry::add(entry *to_add)
{
    this->an_entry = to_add;
    this->an_entry->set_next(to_add);
    return true;
}

//Entry class add new entry function
bool entry::add(char *arg1, char *arg2)
{
    this->an_entry = new entry(arg1, arg2);
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
    if (!an_entry)
        return;
    an_entry->display();
}

//Entry class go to the next pointer
entry *&entry::go_next()
{
    return next;
}

//Entry class add the next entry
void entry::set_next(entry *next_entry)
{
    this->next = next_entry;
}