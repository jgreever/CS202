/** main.cpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * The purpose of this program is to create a calendar type program that will
 * keep track of 3 unique items such as phone calls, events, projects to finish.
 * The project to finish item will be a list of projects to finish.
 * 
 * We are playing with RTTI in this program and learning how to create a base
 * class with all the derived classes similar in function, but with different
 * data. We are going to be able to create a data structure that is a base class
 * object pointer that will be our weekly calendar.
 * 
 * The calendar itself will be using a DLL ADT. We will be using Dynamic Binding
 * to achieve all of this. We will have the base class and at least three other
 * classes with similar functions, and one class that has at least ONE function
 * that is different than the rest so we can experience RTTI in action.
 * 
 */

#include "calendar.hpp"
