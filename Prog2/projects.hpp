#ifndef PROJECTS_HPP
#define PROJECTS_HPP
/** projects.hpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains our derived class, projects.
 * 
 * The purpose of this class is to allow a user to create a new project
 * and add required items to it, as well as a due date. The projects class
 * has a ptr to the list class, which is a LLL that holds the required items
 * for the project (if any).
 * 
 */

#include "calendar.hpp"

//Forward Declarations
class list;

class projects : public entry
{
public:
    //Derived class default constructor
    projects();

    //Derived class default copy constructor
    projects(const projects &to_copy);

    //Derived class default destructor
    ~projects();

    //Self similar functions
    bool add(char *arg1, char *arg2);
    bool edit(entry &to_edit);
    bool remove(entry &to_remove);
    void display() const;

private:
protected:
    char *project_name;
    char *project_due_date;
    list *project_items;
};

//Simple node for our project class to hold an 'Items Needed' LLL
class list : projects
{
public:
    //Default list constructor
    list();

    //Default list copy constructor
    list(const list &to_copy);

    //Default list destructor
    ~list();

    //Self similar functions
    bool add(list *to_add);
    bool edit(list *&to_edit);
    bool remove(list *&to_remove);
    void display() const;

    //ADT functions
    list *&go_next();
    void set_next(list *to_add);

private:
protected:
    list *needed;
    list *next;
};

#endif