#ifndef CONTACT_HPP
#define CONTACT_HPP
/** contact.hpp
 *
 * Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 *
 * This is the file for the Contact class. This is a fairly simple setup.
 *
 */ 

#include "methods.hpp"

/*
//Forward declaration
class contact;

//This acts like the BST
class contact_list //: public contact
{
    public:
        contact_list(); //default constructor
        contact_list(const contact_list &); //copy constructor
        ~contact_list(); //default destructor

        contact_list *search(contact_list *to_search);
        contact_list *add(contact_list *to_add);
        void delete_list();
        void inOrder();
        void preOrder();
        void postOrder();

    private:
        void delete_list(contact_list *a_list);
        void inOrder(contact_list *to_go);
        void preOrder(contact_list *to_go);
        void postOrder(contact_list *to_go);
        contact *root;
};
*/

//This acts like a node
class contact
{
    public:
        contact();
        contact(const contact &to_copy);
        contact(const char *a_name);
        ~contact();
        contact &operator =(const contact &a_contact);
        friend bool operator ==(contact &a_contact, char *a_name);
        friend ostream &operator <<(ostream &a_display, contact &b_display);
        friend istream &operator >>(istream &a_input, contact &b_input);
        friend bool operator >(const contact &a_contact, const contact &b_contact);
        friend bool operator <(const contact &a_contact, const contact &b_contact);
        friend bool operator >=(const contact &a_contact, const contact &b_contact);
        friend bool operator <=(const contact &a_contact, const contact &b_contact);
        friend bool operator >(const contact &a_contact, const char *a_name);

        bool set_left(contact *a_contact);
        bool set_right(contact *a_contact);
        contact *&go_left();
        contact *&go_right();

    private:
        contact *left;
        contact *right;
        char *name;
        device *a_device;
};


#endif
