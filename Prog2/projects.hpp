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
 */

#include "calendar.hpp"

class projects : public entry
{
    public:
        //Derived class default constructor
        projects();

        //Derived class default destructor
        ~projects();

    private:

    protected:
    projects *next;

};

#endif