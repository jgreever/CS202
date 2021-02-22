#ifndef BST_HPP
#define BST_HPP
/* bst.hpp */

/* Justin Greever
 * CS202 - Program 3
 * 2/18/2021
 * 
 * This is the node class header file. It contains the node class and the needed
 * functions for it to work. This is NOT a struct, but an actual class instead.
 * Since we are working with OOP, using a struct would break that concept. This
 * node class will be used in the BST class. The BST class will hold the *root
 * pointer, and the node class will node the *left and *right pointers.
 *
 * I am currently debating the idea of making the node class a derived class
 * of the bst class, but I'm not sure if this is even needed. The node class
 * will hold onto the node *left, *right pointers, a contact *a_contact pointer,
 * and a int height to keep track of the height for balancing.
 *
 * This file contains the BST class as well. It will hold onto the node *root
 * pointer. I currently do not have a firm choice for balancing and what not, 
 * but I am looking into a simple way to do that other than a bunch of node
 * shifting and what not.
 * 
 */ 

#include "contact.hpp"

class node
{
	public:
		node();
		node(const node &to_copy);
		~node();

		friend class bst;

		//Some of these are in public currently for testing.
		//They will be moved to private/protected and have 
		//wrappers created for them.
		int insert(node *to_insert);
		int search(node *to_search, contact *a_contact);
		int remove(node *to_remove);
		int display(node *to_display);

	private:

	protected:
		node *left;
		node *parent;
		contact *a_contact;
		int height;
		node *right;

};

class bst
{
    public:
		bst();
		bst(const bst &to_copy);
		~bst();

    private:
		void insert(contact *to_insert);
		void display_all() const;
		bool search(contact *to_search);
		void remove(contact *to_remove);
		int s_node(contact *a_contact);
		int p_node(contact *a_contact);

    protected:
		node *insert(node *to_insert, contact *a_contact);
		node *search(node *to_search);
		node *remove(node *to_remove, contact *a_contact);
		void display_all(node *to_display) const;
		int s_node(node *a_node); //Successor node
		int p_node(node *a_node); //Predecessor nod
        node *root;
};


#endif