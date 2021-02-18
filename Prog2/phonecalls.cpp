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
phonecalls::phonecalls() : entry(), to_mask(0)
{
    //cout << "\nPhonecalls class constructor called";
}

//Phonecalls class default copy constructor
phonecalls::phonecalls(char *arg1, char *arg2) : entry(arg1, arg2)
{
    //cout << "\nPhonecalls class copy constructor called (char, char)";
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

//Phonecalls class default copy constructor
phonecalls::phonecalls(entry &to_copy) : entry(to_copy)
{
    //cout << "\nPhonecalls class copy constructor called (obj)";
    *this->an_entry = to_copy;
}

//Phonecalls class default destructor
phonecalls::~phonecalls()
{
    if (this->temp1)
        delete[] this->temp1;
    if (this->temp2)
        delete[] this->temp2;
    this->temp1 = this->temp2 = nullptr;
    //cout << "\nPhonecalls class destructor called";
    //if (callee_name)
    //    delete[] callee_name;
    //if (phone_number)
    //    delete[] phone_number;
    //callee_name = phone_number = nullptr;
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
    if (this->temp1)
        delete[] this->temp1;
    if (this->temp2)
        delete[] this->temp2;
    this->temp1 = this->temp2 = nullptr;
    this->temp1 = new char[strlen(arg1) + 1];
    this->temp2 = new char[strlen(arg2) + 1];
    strcpy(this->temp1, arg1);
    strcpy(this->temp2, arg2);
    /*
    if (callee_name)
        delete[] callee_name;
    if (phone_number)
        delete[] phone_number;
    callee_name = phone_number = nullptr;
    callee_name = new char[strlen(arg1) + 1];
    phone_number = new char[strlen(arg2) + 1];
    strcpy(callee_name, arg1);
    strcpy(phone_number, arg2);
    */
    add(this);
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
void phonecalls::display()
{
    cout << "\nCallee Name: " << this->temp1;
    cout << "\nPhone Number: " << this->temp2;
}

//Phonecalls class RTTI (enable_privacy) function
bool phonecalls::enable_privacy(int add_privacy)
{
    return true;
}
