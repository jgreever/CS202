#ifndef BST_HPP
#define BST_HPP

/** cList.hpp
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

#include <iostream>
#include <cctype>
#include <cstring>
#include <istream>
#include <ostream>
#include <fstream>
using namespace std;


// Forward declarations
class device;

class contact
{
    public:
        // Constructors
        contact();
        contact(const contact &);
        ~contact();

        // Operator Overloads
        contact &operator =(const contact &a_contact);
        bool operator ==(const contact &a_contact);
        friend ostream &operator <<(ostream &output, const contact &a_contact);
        friend istream &operator >>(istream &input, contact &a_contact);
        friend bool operator >(const contact &a_contact, const contact &b_contact);
        friend bool operator <(const contact &a_contact, const contact &b_contact);
        friend bool operator >=(const contact &a_contact, const contact &b_contact);
        friend bool operator <=(const contact &a_contact, const contact &b_contact);
        friend bool operator >(const contact &a_contact, const char *a_name);
        friend bool operator <(const contact &a_contact, const char *a_name);

        // Get/Set functions
        bool set_name(char *a_name);
        char *get_name() const;
        contact *&go_left();
        contact *&go_right();
        bool set_left(contact *is_left);
        bool set_right(contact *is_right);

        // Class functions (Wrappers)
        int add(); // Wrapper function for adding contacts
        int edit(char *to_edit); // Wrapper function for editing contacts
        int search(char *to_search); // Wrapper function for searching contacts
        void display(); // Wrapper function for displaying contacts
        void removeAll(); // Wrapper function for removing all contacts

    private:
        int add(contact *&a_contact, char *a_name);
        int edit(contact &a_contact, char *a_name);
        int search(contact &a_contact, char *to_search);
        void display(contact *display);
        void removeAll(contact &to_remove);
        contact *root;
        contact *left;
        contact *right;
        char *contact_name;
        device *a_device;

    protected:

};


#endif