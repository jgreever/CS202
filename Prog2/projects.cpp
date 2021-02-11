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
projects::projects() : project_name(nullptr), project_due_date(nullptr), project_items(nullptr) {}

//Projects class default copy constructor
projects::projects(const projects &to_copy) : entry(to_copy) {}

//Projects class default destructor
projects::~projects() {}

//Projects class add function
bool projects::add(char *arg1, char *arg2) {}

//Projects class edit function
bool projects::edit(entry &to_edit) {}

//Projects class remove function
bool projects::remove(entry &to_remove) {}

//Projects class display function
void projects::display() const {}
