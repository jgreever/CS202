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

contact_list::contact_list() : root(nullptr) {}

contact_list::~contact_list()
{
    contact_list::delete_list();
}

contact_list *contact_list::search(contact_list *to_search) { return this; }
int contact_list::add(contact_list *node) { return 1; }
void contact_list::delete_list() {}
void contact_list::inOrder() {}
void contact_list::preOrder() {}
void contact_list::postOrder() {}

void contact_list::delete_list(contact_list *a_list) 
{
    if (a_list->root)
        delete a_list->root;
    a_list->root = nullptr;
}

void contact_list::inOrder(contact_list *to_go) {}
void contact_list::preOrder(contact_list *to_go) {}
void contact_list::postOrder(contact_list *to_go) {}

 contact::contact() : left(nullptr), right(nullptr), name(nullptr), a_device(nullptr) {}

 contact::contact(contact &to_copy) : left(to_copy.left), right(to_copy.right), name(to_copy.name), a_device(to_copy.a_device)
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

 contact::~contact()
{
    if (this->left)
        delete this->left;
    this->left = nullptr;
    if (this->right)
        delete this->right;
    this->right = nullptr;
    if (this->name)
        delete []this->name;
    this->name = nullptr;
    if (this->a_device)
        delete this->a_device;
    this->a_device = nullptr;
}

 int contact::add(char *to_add)
{
    if (this->name)
        delete []name;
    name = nullptr;
    this->name = new char[strlen(to_add) + 1];
    strcpy(this->name, to_add);
    return 1;
}
 int contact::edit(char *to_edit) { return 1; }

 int contact::search(char *to_search) { return 1; }

 int contact::remove(char *to_remove) { return 1; }

 void contact::display() const {}
