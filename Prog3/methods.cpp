/** methods.cpp
 *
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 *
 * This file holds the three derived classes: phone, pager, voip
 * Each class holds the same phone: number, capabilities
 * Number can be be a few types of things. It can be in the standard
 * telephone number style (555-555-1212), or as a VoIP number similar
 * to phone_extension@ip.address (101@127.0.0.1) or user@domain.name
 *
 * I am going to work on, and hopefully by the time I turn this in, 
 * have the base class, Device, be pure virtual. If that can't happen
 * for some reason, I plan on keeping it simple and using its phone 
 * members to hold the information, much like I did in program 2.
 *
 */
 
#include "methods.hpp"


phone::phone() 
{
    
}

phone::phone(const phone &) 
{
    
}

phone::~phone() 
{
    
}

int phone::add(device *to_add) 
{

    return 1;
}

int phone::remove() 
{

    return 1;
}

void phone::display() const
{
    
}

int phone::search(device *to_search) 
{

    return 1;
}

pager::pager() 
{
    
}

pager::pager(const pager &) 
{
    
}

pager::~pager() 
{
    
}

int pager::add(device *to_add) 
{

    return 1;
}

int pager::remove() 
{

    return 1;
}

void pager::display() const
{
    
}

int pager::search(device *to_search) 
{

    return 1;
}

voip::voip() 
{
    
}

voip::voip(const voip &) 
{
    
}

voip::~voip() 
{
    
}

int voip::add(device *to_add) 
{

    return 1;
}

int voip::remove() 
{

    return 1;
}

void voip::display() const
{
    
}

int voip::search(device *to_search) 
{

    return 1;
}
