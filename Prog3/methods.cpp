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


// Phone class
phone::phone() : number(nullptr), capabilities(nullptr) {}

phone::phone(const phone &copy) : number(copy.number), capabilities(copy.capabilities)
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

phone::~phone()
{
    if (this->number)
        delete []this->number;
    if (this->capabilities)
        delete []this->capabilities;
    this->number = this->capabilities = nullptr;
}


int phone::add(device *to_add)
{

    return 1;
}

int phone::remove() { return 1; }
void phone::display() const {}
int phone::search(device *to_search) { return 1; }


// Pager Class
pager::pager() : number(nullptr), capabilities(nullptr) {}

pager::pager(const pager &copy) : number(copy.number), capabilities(copy.capabilities)
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

pager::~pager()
{
    if (this->number)
        delete []this->number;
    if (this->capabilities)
        delete []this->capabilities;
    this->number = this->capabilities = nullptr;
}

int pager::add(device *to_add)
{

    return 1;
}

int pager::remove() { return 1; }
void pager::display() const {}
int pager::search(device *to_search) { return 1; }


// VoIP class
voip::voip() : number(nullptr), capabilities(nullptr) {}
voip::voip(const voip &copy) : number(copy.number), capabilities(copy.capabilities)
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

voip::~voip()
{
    if (this->number)
        delete []this->number;
    if (this->capabilities)
        delete []this->capabilities;
    this->number = this->capabilities = nullptr;
}

int voip::add(device *to_add)
{

    return 1;
}

int voip::remove() { return 1; }
void voip::display() const {}
int voip::search(device *to_search) { return 1; }