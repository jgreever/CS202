/** projects.cpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains our derived class, projects.
 * 
 */

#include "projects.hpp"

//Projects class default constructor
projects::projects() : entry(), project_items(nullptr)
{
    //cout << "\nProjects class constructor called";
}

//Projects class default copy constructor
projects::projects(char *arg1, char *arg2) : entry(arg1, arg2)
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
//Projects class default copy constructor
projects::projects(entry &to_copy) : entry(to_copy)
{
    //cout << "\nProjects class copy constructor called";
    *this->an_entry = to_copy;
}

//Projects class default destructor
projects::~projects()
{
    if (this->temp1)
        delete[] this->temp1;
    if (this->temp2)
        delete[] this->temp2;
    this->temp1 = this->temp2 = nullptr;
    //cout << "\nProjects class destructor called";
}

//Projects class add function
bool projects::add(entry *to_add)
{
    this->an_entry = to_add;
    return true;
}

//Projects class add function
bool projects::add(char *arg1, char *arg2)
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
    add(this);
    return true;
}

//Projects class edit function
bool projects::edit(entry &to_edit)
{
    return true;
}

//Projects class remove function
bool projects::remove(entry &to_remove)
{
    return true;
}

//Projects class display function
void projects::display()
{
    cout << "\nProject Name: " << this->temp1;
    cout << "\nProject Due Date: " << this->temp2;
}

//List class functions
//List class default constructor
list::list() : needed(nullptr), next(nullptr)
{
}

//List default copy constructor
list::list(list &to_copy) : needed(to_copy.needed), next(to_copy.next)
{
}

//List default destructor
list::~list()
{
    if (this->needed)
        delete[] this->needed;
    this->needed = nullptr;
    if (this->next)
        delete this->next;
    this->next = nullptr;
}

bool list::add_list(list *to_add)
{

    return true;
}

bool list::edit_list(list *&to_edit)
{

    return true;
}

bool list::remove_list(list *&to_remove)
{

    return true;
}

void list::display_list()
{
    cout << "\nNeeded: " << this->needed;
}

list *&list::go_next()
{
    return this->next;
}

void list::set_next(list *to_add)
{
    this->next = to_add;
}