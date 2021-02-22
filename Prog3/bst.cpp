/* bst.cpp */

/* Justin Greever
 * CS202 - Program 2
 * 2/18/2021
 * 
 * This is the BST functions file. In here we have functions to control
 * inserting, searching, displaying/all, and removing a node. I would like
 * to have working successor/predecessor functions working as well, but that
 * is if time allows, they are not super critical to the overall program.
 * 
 */

#include "bst.hpp"

node::node() : left(nullptr), parent(nullptr), a_contact(nullptr), height(0), right(nullptr)
{

}

node::node(const node &to_copy) : left(to_copy.left), parent(to_copy.parent), a_contact(to_copy.a_contact), height(to_copy.height), right(to_copy.right)
{
    if(this->left)
        delete this->left;
    if(this->parent)
        delete this->parent;
    if(this->a_contact)
        delete this->a_contact;
    height = 0;
    if (this->right)
        delete this->right;
    this->left = to_copy.left;
    this->parent = to_copy.parent;
    this->a_contact = to_copy.a_contact;
    this->height = to_copy.height;
    this->right = to_copy.right;
}

node::~node()
{
    if(this->left)
        delete this->left;
    if(this->parent)
        delete this->parent;
    if(this->a_contact)
        delete this->a_contact;
    height = 0;
    if (this->right)
        delete this->right;
    this->left = this->parent = this->right = nullptr;
    this->a_contact = nullptr;
    height = 0;
}

bst::bst() : root(nullptr)
{

}

bst::bst(const bst &to_copy) : root(to_copy.root)
{
    if(this->root)
        delete this->root;
    this->root = to_copy.root;
}

bst::~bst()
{
    if(this->root)
        delete this->root;
    this->root = nullptr;
}

void bst::insert(contact *to_insert)
{
    root = insert(root,to_insert);
}

void bst::display_all() const
{

}

bool bst::search(contact *to_search)
{

    return false;
}

void bst::remove(contact *to_remove)
{

}

int bst::s_node(contact *a_contact)
{

    return 0;
}

int bst::p_node(contact *a_contact)
{

    return 0;
}

node *bst::insert(node *to_insert, contact *a_contact)
{
    if(!to_insert)
    {
        to_insert = new node;
        to_insert->a_contact = a_contact;
        to_insert->left = nullptr;
        to_insert->right = nullptr;
        to_insert->parent = nullptr;
        to_insert->height = 0;
    }
    else if(to_insert->a_contact < a_contact)
    {
        to_insert->right = insert(to_insert->right, a_contact);
        to_insert->right->parent = to_insert;
    }
    else
    {
        to_insert->left = insert(to_insert->left, a_contact);
        to_insert->left->parent = to_insert;
    }
    return to_insert;
}

node *bst::search(node *to_search)
{

    return nullptr;
}

node *bst::remove(node *to_remove, contact *a_contact)
{

    return nullptr;
}

void bst::display_all(node *to_display) const
{

}

int bst::s_node(node *a_node)
{

    return 0;
}

int bst::p_node(node *a_node)
{

    return 0;
}
