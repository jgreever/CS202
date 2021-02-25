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

int contact_list::search() { return 1; }
int contact_list::add() { return 1; }
void contact_list::delete_list() {}
void contact_list::inOrder() {}
void contact_list::preOrder() {}
void contact_list::postOrder() {}
contact_list *contact_list::search(contact_list *to_search) { return this; }

int contact_list::add(contact_list *node)
{
    return 1;
}

void contact_list::delete_list(contact_list *a_list) 
{
    if (a_list->root)
        delete a_list->root;
    a_list->root = nullptr;
}

void contact_list::inOrder(contact_list *to_go) {}
void contact_list::preOrder(contact_list *to_go) {}
void contact_list::postOrder(contact_list *to_go) {}

template <class Type>
contact<Type>::contact() : left(nullptr), right(nullptr), name(nullptr), a_device(nullptr) {}

template <class Type>
contact<Type>::contact(contact &to_copy) : left(to_copy.left), right(to_copy.right), name(to_copy.name), a_device(to_copy.device)
{
    if (!to_copy)
        this = nullptr;
    else
    {
        this->left = to_copy.left;
        this->right = to_copy.right;
        this->name = new char[strlen(to_copy.name) + 1];
        strcpy(this->name, to_copy.name);
    }
}

template <class Type>
contact<Type>::~contact()
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

template <class Type>
int contact<Type>::add(char *to_add, device<Type> *a_device)
{
    if (this->name)
        delete []name;
    name = nullptr;
}