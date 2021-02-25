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

class contact_list;
//template <class Type>
class contact
{
    public:
        contact();
        contact(contact &to_copy);
        ~contact();
        int add(char *to_add);
        int edit(char *to_edit);
        int search(char *to_search);
        int remove(char *to_remove);
        void display() const;


    private:
        contact_list *left;
        contact_list *right;
        char *name;
        device *a_device;
};

class contact_list : public contact
{
    public:
        contact_list();
        ~contact_list();
        contact_list *search(contact_list *to_search);
        int add(contact_list *node);
        void delete_list();
        void inOrder();
        void preOrder();
        void postOrder();

    private:
        //contact_list *search(contact_list *to_search);
        //int add(contact_list *node);
        void delete_list(contact_list *a_list);
        void inOrder(contact_list *to_go);
        void preOrder(contact_list *to_go);
        void postOrder(contact_list *to_go);
        contact_list *root;
};


#endif
