#ifndef NODE_H
#define NODE_H

/** node.hpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 * This file manages our node class. This file contains the needed
 * classes for the LLL for tracking, and the ARR for product categories
 * and a queue setup for keeping track of item priority so we don't have
 * to do a bunch of traversal.
 * 
 */

#include "warehouse.hpp"


//The node class is not fully finished. I am working on a method that
//will allow me to combine the needed classes with the node.h file
//so that I can ensure proper OOP is being done.
class node
{
    public:
        //Default constructor
        node();

        //Default destructor
        ~node();


    protected:
        node *head;
        char *been_where;
        char *currently_at;
        node *next;

};

#endif