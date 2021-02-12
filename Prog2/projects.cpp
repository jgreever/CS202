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
projects::projects() : project_name(nullptr), project_due_date(nullptr), project_items(nullptr)
{
    cout << "\nProjects class constructor called";
}

//Projects class default copy constructor
projects::projects(const projects &to_copy) : entry(to_copy)
{
    cout << "\nProjects class copy constructor called";
    *this = to_copy;
}

//Projects class default destructor
projects::~projects()
{
    cout << "\nProjects class destructor called";
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
void projects::display() const {}
