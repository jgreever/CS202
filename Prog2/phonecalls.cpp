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
phonecalls::phonecalls() : callee_name(nullptr), phone_number(nullptr)
{
    cout << "\nPhonecalls class constructor called";
}

//Phonecalls class default copy constructor
phonecalls::phonecalls(char *arg1, char *arg2) : callee_name(arg1), phone_number(arg2)
{
    cout << "\nPhonecalls class copy constructor called (char, char)";
    this->callee_name = new char[strlen(arg1) + 1];
    strcpy(this->callee_name, arg1);
    this->phone_number = new char[strlen(arg2) + 1];
    strcpy(this->phone_number, arg2);
}

//Phonecalls class default copy constructor
phonecalls::phonecalls(const phonecalls &to_copy) : entry(to_copy)
{
    cout << "\nPhonecalls class copy constructor called (obj)";
    *this = to_copy;
}

//Phonecalls class default destructor
phonecalls::~phonecalls()
{
    cout << "\nPhonecalls class destructor called";
    if (callee_name)
        delete[] callee_name;
    if (phone_number)
        delete[] phone_number;
    callee_name = phone_number = nullptr;
}


//Phonecalls class add function
bool phonecalls::add(entry *to_add)
{
    this->an_entry = to_add;
    return true;
}

//Phonecalls class add function
bool phonecalls::add(char *arg1, char *arg2)
{
    return true;
}

//Phonecalls class edit function
bool phonecalls::edit(entry &to_edit)
{
    return true;
}

//Phonecalls class remove function
bool phonecalls::remove(entry &to_remove)
{
    return true;
}

//Phonecalls class display function
void phonecalls::display() const {}

//Phonecalls class RTTI (enable_privacy) function
bool phonecalls::enable_privacy(int add_privacy)
{
    return true;
}
