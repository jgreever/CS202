/** phonecalls.cpp
 * 
 * Justin Greever
 * CS202 - Program 2
 * 02/01/2021
 * 
 * This file contains a derived class, phonecalls.
 * 
 */

#include "phonecalls.hpp"

//Phonecalls class default constructor
phonecalls::phonecalls() : callee_name(nullptr), phone_number(nullptr) {}

//Phonecalls class default copy constructor
phonecalls::phonecalls(const phonecalls &to_copy) : entry(to_copy) {}

//Phonecalls class default destructor
phonecalls::~phonecalls() {}

//Phonecalls class add function
bool phonecalls::add(char *arg1, char *arg2) {}

//Phonecalls class edit function
bool phonecalls::edit(entry &to_edit) {}

//Phonecalls class remove function
bool phonecalls::remove(entry &to_remove) {}

//Phonecalls class display function
void phonecalls::display() const {}

//Phonecalls class RTTI (enable_privacy) function
bool phonecalls::enable_privacy(int add_privacy) {}
