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
calendar::calendar() : head(nullptr), tail(nullptr), prev(nullptr), next(nullptr), day(nullptr)
{
    //cout << "\nCalendar class constructor called";
}

//Calendar class default copy constructor
calendar::calendar(calendar &to_copy) : head(to_copy.head), tail(to_copy.tail), prev(to_copy.prev), next(to_copy.next), day(to_copy.day)
{
    //cout << "\nCalendar class copy constructor called";
}

//Calendar class default destructor
calendar::~calendar()
{
    //cout << "\nCalendar class destructor called";
    if (head)
    {
        delete head;
        head = nullptr;
    }
    delete tail;
    head = tail = nullptr;
    prev = next = nullptr;
    //day_num = 0;
    if (day)
    {
        delete day;
        day = nullptr;
    }
}

//Calendar class DLL functions
calendar *&calendar::go_prev()
{
    return prev;
}

calendar *&calendar::go_next()
{
    return next;
}

void calendar::set_prev(calendar *is_prev)
{
    prev = is_prev;
}

void calendar::set_next(calendar *is_next)
{
    next = is_next;
}

//Calendar class add function
bool calendar::add(entry &to_insert)
{
    /*
    if (!head) //no list, create a new one
    {
        head = new calendar;
        tail = head;
        head->day = new entry;
        head->day->add(to_insert);
        head->set_next(nullptr);
        head->set_prev(nullptr);

        return true;
    }
    else if (!head->go_next()) //only one node, create a new one and link them
    {
        
        node *temp = new node;
        entry *day = new entry;
        day = to_insert;
        temp->day = new entry;
        temp->day->add(day);
        temp->set_prev(head);
        head->set_next(temp);
        temp->set_next(tail);
        tail->set_prev(temp);
        tail->set_next(nullptr);
        return true;
    }
    else if (!&head->go_next())
    {
        calendar *temp = new calendar;
        temp->day = new entry;
        temp->day->add(to_insert);
        temp->set_prev(head);
        temp->set_next(nullptr);
        head->set_next(temp);
        tail = temp;
    }
    else
    {
        calendar *temp = new calendar;
        temp->day = new entry;
        temp->day->add(to_insert);
        temp->set_prev(&tail->go_prev());
        temp->set_next(nullptr);
        tail = temp;
    }
    return true;
    */
    return add(head, to_insert);
}

bool calendar::add(calendar *&to_add, entry &to_insert)
{
    calendar *temp = nullptr;

    if (!to_add)
    {
        temp = new calendar;
        temp->day = new entry;
        temp->day->add(&to_insert);
        temp->set_next(nullptr);
        temp->set_prev(nullptr);
        to_add = temp;
        return true;
    }
    else if (!to_add->go_next())
    {
        temp = new calendar;
        temp->day = new entry;
        temp->day->add(&to_insert);
        temp->set_next(nullptr);
        temp->set_prev(to_add);
        to_add->set_next(temp);
        return true;
    }
    return add(to_add->go_next(), to_insert);
}

/* 
//Calendar class add function
bool calendar::add(entry *&to_insert)
{
    if (!head) //no list, create a new one
    {
        calendar *head = new calendar;
        calendar *tail = head;
        head->day = new entry;
        head->day->add(to_insert);
        head->set_prev(nullptr);
        head->set_next(nullptr);
        //tail->set_prev(head);
        //tail->set_next(nullptr);
        return true;
    }
    else if (!&head->go_next()) //only one node, create a new one and link them
    {
        calendar *temp = new calendar;
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
        calendar *temp = new calendar;
        calendar *curr = head;
        temp->day = new entry;
        temp->day->add(to_insert);
        if (tail)
        {
            *curr = tail->go_prev();
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
 */

//Calendar class remove function
bool calendar::remove(entry &to_remove)
{
    return true;
}

//Calendar class display calendar wrapper function
void calendar::display()
{
    if (!head)
        return;
    //head->day->display();
    display(head, head->day);
}

//Calendar class display calendar function
void calendar::display(calendar *&to_display, entry *&disp)
{
    /*
    if (!disp)
        return;
    disp->display();
    if (disp->go_next())
    {
        //this->day->go_next();
        disp->display();
    }
    else
        return;
*/
    if (!to_display)
        return;
    if (!disp)
    {
        if (to_display->go_next())
        {
            display(to_display->go_next(), to_display->go_next()->day);
        }
        return;
        //disp->display();
        //display(disp->go_next());
    }
    disp->display();
    display(to_display, disp->go_next());
}

//Calendar class search function
bool calendar::search(const entry *to_search)
{
    return true;
}

bool calendar::remove_all()
{
    return remove_all(head);
}
//Calendar class remove all function
bool calendar::remove_all(calendar *&to_remove)
{
    calendar *temp = new calendar;
    if (!head)
    {
        delete head;
        head = nullptr;
        return;
    }
    if (head)
    {
        temp = head->go_next();
        delete head;
        head = nullptr;
        head = temp;
    }
    return remove_all(head->go_next());
}

/*
//Node class functions
//node class default constructor
node::node() : prev(nullptr), next(nullptr)
{
    //cout << "\nNode class constructor called";
}

//node class copy constructor
node::node(entry &to_copy) : a_day(&to_copy)
{
    *this = to_copy;
    //cout << "\nNode class copy constructor called (obj)";
}

//node class go_next function
node *&node::go_next()
{
    return this->next;
}

//node class go_prev function
node *&node::go_prev()
{
    return this->prev;
}

//node class set_next function
void node::set_next(node *next_node)
{
    this->next = next_node;
    //next_node->prev = this;
}

//node class set_prev function
void node::set_prev(node *prev_node)
{
    this->prev = prev_node;
    //prev_node->next = this;
}
*/

//Entry class functions
//Entry class default constructor
entry::entry() : temp1(nullptr), temp2(nullptr), an_entry(nullptr), next(nullptr)
{
    //cout << "\nEntry class constructor called";
}

//entry class default copy constructor
entry::entry(char *arg1, char *arg2) : temp1(arg1), temp2(arg2), an_entry(nullptr), next(nullptr)
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
}

//Entry class default copy constructor (obj)
entry::entry(entry &to_copy) : temp1(to_copy.temp1), temp2(to_copy.temp2), an_entry(to_copy.an_entry), next(to_copy.next)
{
    *this = to_copy;
    //cout << "\nEntry class copy constructor called";
}

//Entry class VIRTUAL default destructor
entry::~entry()
{
    //cout << "\nEntry class destructor called";
    if (this->temp1)
        delete[] this->temp1;
    this->temp1 = nullptr;
    if (this->temp2)
        delete[] this->temp2;
    this->temp2 = nullptr;
    //if (this->an_entry)
    //    delete this->an_entry;
    //this->an_entry = nullptr;
    if (this->next)
        delete this->next;
    this->next = nullptr;
}

//Entry class add new entry function
bool entry::add(entry *to_add)
{
    /*
    an_entry = to_add;
    an_entry->set_next(to_add);
    */
    if (this->an_entry)
        this->an_entry->set_next(to_add);
    else
    {
        this->an_entry = to_add;
        this->an_entry->set_next(nullptr);
    }
    return true;
}

//Entry class add new entry function
bool entry::add(char *arg1, char *arg2)
{
    this->temp1 = new char[strlen(arg1) + 1];
    this->temp2 = new char[strlen(arg2) + 1];
    strcpy(this->temp1, arg1);
    strcpy(this->temp2, arg2);
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
    if (!this->an_entry)
        return;
    cout << "\nOutput 1: " << an_entry->temp1;
    cout << "\nOutput 2: " << an_entry->temp2;
}

//Entry class go to the next pointer
entry *&entry::go_next()
{
    return this->next;
}

//Entry class add the next entry
void entry::set_next(entry *next_entry)
{
    this->next = next_entry;
}