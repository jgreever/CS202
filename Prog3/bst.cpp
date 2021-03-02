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

#include "methods.hpp"

// Contact class functions
// Default class constructor
contact::contact() : root(nullptr), left(nullptr), right(nullptr), contact_name(nullptr), a_device(nullptr)
{
    // This is the default constructor. We don't need to add any
    // code for this function as it is all done in the initialization list
}

// Default copy constructor
contact::contact(const contact &a_contact) : left(a_contact.left), right(a_contact.right), contact_name(a_contact.contact_name), a_device(a_contact.a_device)
{
    this->root = a_contact.root;
    if (this->contact_name)
    {
        this->contact_name = new char[strlen(a_contact.contact_name) + 1];
        strcpy(this->contact_name, a_contact.contact_name);
    }
    this->a_device = a_contact.a_device;
}

// Default class destructor
contact::~contact()
{
    root = left = right = nullptr;
    if (contact_name)
        delete []contact_name;
    contact_name = nullptr;
    if (a_device)
        delete a_device;
    a_device = nullptr;
}

// Operator overloads for contact class
// Copy Assignment Operator (=)
contact &contact::operator =(const contact &a_contact)
{
    if (this != &a_contact) {
        this->contact_name = new char[strlen(a_contact.contact_name) + 1];
        strcpy(this->contact_name, a_contact.contact_name);
    }
    return *this;
}

// Equality Assignment Operator (==)
bool contact::operator ==(const contact &a_contact)
{
    return strcmp(this->contact_name, a_contact.contact_name) == 0;
}

// Stream Extraction Assignment Operator
ostream &operator <<(ostream &output, const contact &a_contact)
{
    output << "\nContact Info:\n" << a_contact.contact_name << endl;
    return output;
}

// Stream Insertion Assignment Operator
istream &operator >>(istream &input, contact &a_contact)
{
    char temp[256];
    cout << "\nEnter the contact name: ";
    input.get(temp, 256, '\n');
    input.ignore(256, '\n');
    int length = strlen(temp) + 1;
    a_contact.contact_name = new char[length];
    strcpy(a_contact.contact_name, temp);
    return input;
}

bool operator >(const contact &a_contact, const contact &b_contact)
{
    return strcmp(a_contact.contact_name, b_contact.contact_name) > 0;
}

bool operator <(const contact &a_contact, const contact &b_contact)
{
    return strcmp(a_contact.contact_name, b_contact.contact_name) < 0;
}

bool operator >=(const contact &a_contact, const contact &b_contact)
{
    return strcmp(a_contact.contact_name, b_contact.contact_name) >= 0;
}

bool operator <=(const contact &a_contact, const contact &b_contact)
{
    return strcmp(a_contact.contact_name, b_contact.contact_name) <= 0;
}

bool operator >(const contact &a_contact, const char *a_name)
{
    return strcmp(a_contact.contact_name, a_name) > 0;
}

bool operator <(const contact &a_contact, const char *a_name)
{
    return strcmp(a_contact.contact_name, a_name) < 0;
}

bool contact::set_name(char *a_name) {
    this->contact_name = a_name;
    return true;
}

char *contact::get_name() const {
    return this->contact_name;
}

contact *&contact::go_left() {

    return this->left;
}

contact *&contact::go_right()
{
    return this->right;
}

bool contact::set_left(contact *is_left)
{
    this->left = is_left;
    return true;
}

bool contact::set_right(contact *is_right)
{
    this->right = is_right;
    return true;
}

int contact::add() {

    contact *temp = new contact;
    //temp->contact_name = new char;
    cin >> *temp;
    add(root, temp->contact_name);
    //delete temp;
    return 1;

}

int contact::edit(char *to_edit)
{

    return 1;
}

int contact::search(char *to_search)
{
    root->go_left();
    if (root->contact_name == to_search)
        return 1;
    root->go_right();
    return 0;
}

void contact::display() {

    display(root);
}

void contact::display(contact *to_display)
{
    //if (to_display->left || to_display->right) {
    cout << *to_display;
    if (to_display->right) {
        to_display = to_display->go_right();
        return display(to_display);
    }
    if (to_display->left) {
        to_display = to_display->go_left();
        return display(to_display);
    }
}

void contact::removeAll()
{
    removeAll(*root);
}

int contact::add(contact *&root, char *a_name)
{
    if (!root) {
        root = new contact;
        root->set_name(a_name);
        root->set_left(nullptr);
        root->set_right(nullptr);
        return 1;
    }
    else if(a_name < root->contact_name) {
        add(root->go_left(), a_name);
    }
    else if(a_name > root->contact_name) {
        add(root->go_right(), a_name);
    }
    else {
        cout << "Entry already exists.\n";
        return 0;
    }
   return 0;
}

int contact::edit(contact &a_contact, char *a_name)
{
    return 1;
}

int contact::search(contact &a_contact, char *to_search)
{
    return 1;
}

void contact::removeAll(contact &to_remove) {

    if (!root) return;
    removeAll(*root->go_left());
    removeAll(*root->go_right());

}