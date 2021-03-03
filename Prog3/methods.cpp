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


phone::phone() : number(nullptr), capabilities(nullptr)
{
    // Default constructor, no args needed
}

phone::phone(const phone &toCopy) : number(toCopy.number), capabilities(toCopy.capabilities)
{
    if (number)
        delete number;
    if (capabilities)
        delete capabilities;
    number = new char[strlen(toCopy.number) + 1];
    strcpy(number, toCopy.number);
    capabilities = new char[strlen(toCopy.capabilities) + 1];
    strcpy(capabilities, toCopy.capabilities);
}

phone::~phone() 
{
    if (number)
        delete number;
    if (capabilities)
        delete capabilities;
    number = capabilities = nullptr;
}

ostream &operator <<(ostream &output, const phone &a_device) {

    output << "\nDevice:\n" << a_device.number << endl;
    output << "\nDevice Capabilities:\n" << a_device.capabilities << endl;
    return output;
}

istream &operator >>(istream &input, phone &a_device) {

    char temp[256];
    cout << "\nEnter the devices phone number: ";
    input.get(temp, 256, '\n');
    input.ignore(256, '\n');
    int length = strlen(temp) + 1;
    a_device.number = new char[length];
    strcpy(a_device.number, temp);

    char temp2[256];
    cout << "\nEnter the device capabilities:\n(example: Phonecalls, Messaging, 1-Way Messaging, 2-Way Messaging, VoIP address...\n";
    input.get(temp2, 256, '\n');
    input.ignore(256, '\n');
    int length2 = strlen(temp2) + 1;
    a_device.capabilities = new char[length2];
    strcpy(a_device.capabilities, temp2);

    return input;
}

int phone::add()
{
    //phone *aPhone = new phone();
    this->number = new char;
    this->capabilities = new char;
    cin >> *this;
    return 1;
}

int phone::remove() 
{

    return 1;
}

void phone::display() const
{
    if (this->number && this->capabilities)
        cout << *this;
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

int pager::add() 
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

int voip::add() 
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
