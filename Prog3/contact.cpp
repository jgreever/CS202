/** contact.cpp
 * 
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 * 
 * This file contains the functions for the contact class. This will be
 * the start of our BST. A new BST object will be created in main.cpp
 * that points to this class.
 * 
 */

#include "contact.hpp"
using namespace std;


contact_list::contact_list() : root(nullptr) {}

contact_list::contact_list(const contact_list &to_copy) : root(to_copy.root)
{
    
}

contact_list::~contact_list()
{
    contact_list::delete_list();
}

contact_list contact_list::search(contact *to_search)
{
    return *this;
}

contact_list contact_list::add(contact *to_add)
{
    if (!root)
    {
        root = new contact(*to_add);
        return *this;
    }
    else if (to_add->name > root->name)
    {
        return *this;
    }
    return *this;
}

void contact_list::delete_list() {}

void contact_list::inOrder() {}

void contact_list::preOrder() {}

void contact_list::postOrder() {}

void contact_list::delete_list(contact *a_list) 
{
}

void contact_list::inOrder(contact *to_go) {}

void contact_list::preOrder(contact *to_go) {}

void contact_list::postOrder(contact *to_go) {}

contact::contact() : left(nullptr), right(nullptr), name(nullptr), a_device(nullptr) {}

contact::contact(const contact &to_copy) : left(to_copy.left), right(to_copy.right), name(to_copy.name), a_device(to_copy.a_device)
{
    if (!to_copy.name)
        this->name = nullptr;
    if (!to_copy.a_device)
        this->a_device = nullptr;
    else
    {
        this->left = to_copy.left;
        this->right = to_copy.right;
        this->name = new char[strlen(to_copy.name) + 1];
        strcpy(this->name, to_copy.name);
    }
}

contact::contact(const char *a_name)
{
    if (this->name)
        delete []this->name;
    this->name = nullptr;
    this->name = new char[strlen(a_name) + 1];
    strcpy(this->name, a_name);
}

contact::~contact()
{
    if (this->left)
        delete this->left;
    if (this->right)
        delete this->right;
    if (this->name)
        delete []this->name;
    if (this->a_device)
        delete this->a_device;
    this->left = this->right = nullptr;
    this->name = nullptr;
    this->a_device = nullptr;
}

contact &contact::operator =(const contact &a_contact)
{
    if (this == &a_contact)
        return *this;
    if (name)
        delete []name;
    name = new char[strlen(a_contact.name) + 1];
    strcpy(name, a_contact.name);
    a_device->add(a_contact.a_device);
    return *this;
}

bool operator ==(const contact &a_contact, const char *a_name)
{
    if (strcmp(a_contact.name, a_name) == 0)
        return true;
    else
        return false;
}

ostream &operator <<(ostream &a_display, contact &b_display)
{
    a_display << b_display.name;
    return a_display;
}

istream &operator >>(istream &a_input, contact &b_contact)
{
    char temp[101];
    a_input >> temp;
    b_contact.name = new char[strlen(temp) + 1];
    strcpy(b_contact.name, temp);
    return a_input;
}

bool operator >(const contact &a_contact, const contact &b_contact)
{
    if (strcmp(a_contact.name, b_contact.name) > 0)
        return true;
    else
        return false;

}

bool operator <(const contact &a_contact, const contact &b_contact)
{
    if (strcmp(a_contact.name, b_contact.name) < 0)
        return true;
    else
        return false;
}

bool operator >=(const contact &a_contact, const contact &b_contact)
{
    if ((strcmp(a_contact.name, b_contact.name) > 0) || (strcmp(a_contact.name, b_contact.name) == 0))
        return true;
    else
        return false;
}

bool operator <=(const contact &a_contact, const contact &b_contact)
{
    if ((strcmp(a_contact.name, b_contact.name) < 0) || (strcmp(a_contact.name, b_contact.name) == 0))
        return true;
    else
        return false;
}

bool operator >(const contact &a_contact, const char *a_name)
{
    if (strcmp(a_contact.name, a_name) > 0)
        return true;
    else
        return false;
}

bool operator <(const contact &a_contact, const char *a_name)
{
    if (strcmp(a_contact.name, a_name) < 0)
        return true;
    else
        return false;
}

bool contact::set_left(contact *a_contact)
{
    this->left = a_contact;
    return true;
}

bool contact::set_right(contact *a_contact)
{
    this->right = a_contact;
    return true;
}

contact *&contact::go_left()
{
    return this->left;
}

contact *&contact ::go_right()
{
    return this->right;
}
