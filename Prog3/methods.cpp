/** methods.cpp
 * 
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 * 
 * This file contains the functions for the methods class.
 * 
 */

#include "methods.hpp"
using namespace std;

template <class Type>
phone<Type>::phone() : number(nullptr), capabilities(nullptr) {}

template <class Type>
phone<Type>::phone(const Type &copy) : number(copy.number), capabilities(copy.capabilities)
{
    if (!copy.number && !copy.capabilities)
    {
        this->number = nullptr;
        this->capabilities = nullptr;
    }
    else
    {
        this->number = new char[strlen(copy.number) + 1];
        this->capabilities = new char[strlen(copy.capabilities) + 1];
        strcpy(this->number, copy.number);
        strcpy(this->capabilities, copy.capabilities);
    }
}

template <class Type>
phone<Type>::~phone()
{
    if (this->number)
        delete []this->number;
    if (this->capabilities)
        delete []this->capabilities;
    this->number = this->capabilities = nullptr;
}

template <class Type>
int phone<Type>::add(Type *to_add)
{

}