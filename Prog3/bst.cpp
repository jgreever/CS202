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
contact::contact(const contact &a_contact) : /* root(root) */ left(a_contact.left), right(a_contact.right), contact_name(a_contact.contact_name), a_device(a_contact.a_device)
{
    this->root = a_contact.root;
    if (this->contact_name)
    {
        this->contact_name = new char[strlen(a_contact.contact_name) + 1];
        strcpy(this->contact_name, a_contact.contact_name);
    }
    this->left = a_contact.left;
    this->right = a_contact.right;
    this->a_device = a_contact.a_device;
}

// Default class destructor
contact::~contact()
{
    this->root = this->left = this->right = nullptr;
    if (this->contact_name)
        delete []this->contact_name;
    this->contact_name = nullptr;
    if (this->a_device)
        delete this->a_device;
    this->a_device = nullptr;
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
    char* temp;
    int size(256);
    temp = new char[size];
    cout << "\nEnter the contact name: ";
    input.get(temp, size, '\n');
    input.ignore(100, '\n');
    a_contact.contact_name = new char[strlen(temp) + 1];
    strcpy(a_contact.contact_name, temp);
    delete []temp;

    return input;


    /* cout << "\nEnter the contacts name: ";
    char *temp = new char;
    input.get(temp, 100, '\n');
    if (a_contact.contact_name) {
        delete []a_contact.contact_name;
    }
    a_contact.contact_name = new char[strlen(temp) + 1];
    strcpy(a_contact.contact_name, temp);

    return input;
    */
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
    //if (!this->left) {
    //    this->left = new contact;
    //    this->left = nullptr;
    //}
    return this->left;
}

contact *&contact::go_right()
{
    //if (!this->right) {
    //    this->right = new contact;
    //    this->right = nullptr;
    //}
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
    temp->contact_name = new char;
    cin >> *temp;
    return add(root, temp->contact_name);
    //return 1;

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

void contact::display()
{
    if (!root) return;
    if (!root->left && !root->right)
        cout << *root;
    if (root->left)
        root->go_left();
    if (root->right)
        root->go_right();
    //root->go_left();
    //root->go_right();
    //cout << *root;
}

void contact::removeAll()
{
    removeAll(root);
}

int contact::add(contact *&a_contact, char *a_name)
{
    if (!root) {
        root = new contact;
        root->left = root->right = nullptr;
        root->set_name(a_name);
        return 1;
    }
    if (root->contact_name < a_name) {
        //set_left(a_contact);
        add(root->go_left(), a_name);
    }
    if (root->contact_name > a_name) {
        //set_right(a_contact);
        add(root = root->go_right(), a_name);
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

void contact::removeAll(contact *&to_remove) {

    if (!root) return;
    removeAll(root->go_left());
    removeAll(root->go_right());

}