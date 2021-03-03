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
    //removeAll(root);
    root = left = right = nullptr;
    if (this->contact_name)
        delete []this->contact_name;
    if (this->a_device)
        delete this->a_device;
    this->a_device = nullptr;
    this->contact_name = nullptr;
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

// Stream Insertion Assignment Operator
ostream &operator <<(ostream &output, const contact &a_contact)
{
    output << "\n\n\nContact Info:\n" << a_contact.contact_name << endl;
    a_contact.a_device->display();
    return output;
}

// Stream Extraction Assignment Operator
istream &operator >>(istream &input, contact *a_contact)
{
    char hold[256];
    cout << "\nEnter the contact name: ";
    input.get(hold, 256);
    input.ignore(100, '\n');
    strcpy(a_contact->contact_name, hold);

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
    temp->contact_name = new char[256];
    cin >> temp;
    root->add(this->root, temp->contact_name);
    //delete temp;
    return 1;

}

int contact::edit(char *to_edit)
{

    return 1;
}

int contact::search(char *to_search)
{
    search(root, to_search);
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

int contact::add(contact *&root, char *a_name)
{
    if (!root) {
        root = new contact;
        root->a_device = new phone;
        root->set_name(a_name);
        root->a_device->add();
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
        return 0;
    }
    return 0;
}

int contact::edit(contact &a_contact, char *a_name)
{
    return 1;
}

int contact::search(contact *a_contact, char *to_search) {

    if (strcmp(a_contact->contact_name, to_search) == 0) {
        cout << "\nEntry found!\n";
        cout << *a_contact;
    }
    if (a_contact->right) {
        a_contact = a_contact->go_right();
        return search(a_contact, to_search);
    }
    if (a_contact->left) {
        a_contact = a_contact->go_left();
        return search(a_contact, to_search);
    }
    else
        cout << "\nEntry not found...\n";  
    return 1;
}

void contact::removeAll() {
    removeAll(root);
}

void contact::removeAll(contact *&cList) {

    while (cList->root) {
        removeAll(cList->root->go_left());
        removeAll(cList->root->go_right());
        delete cList->root;
    }
    delete root;
    root = nullptr;
}