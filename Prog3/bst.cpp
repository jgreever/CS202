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

node::node() : left(nullptr), parent(nullptr), a_contact(nullptr), right(nullptr) {}

node::node(const node &to_copy) : left(to_copy.left), parent(to_copy.parent), a_contact(to_copy.a_contact), right(to_copy.right)
{
    if(this->left)
        delete this->left;
    if(this->parent)
        delete this->parent;
    if(this->a_contact)
        delete this->a_contact;
    if (this->right)
        delete this->right;
    this->left = to_copy.left;
    this->parent = to_copy.parent;
    this->a_contact = to_copy.a_contact;
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
    if (this->right)
        delete this->right;
    this->left = this->parent = this->right = nullptr;
    this->a_contact = nullptr;
}

bst::bst() : root(nullptr) {}

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
    if(!root) return;
}

bool bst::search(contact *to_search)
{

    return false;
}

void bst::remove(contact *to_remove)
{
    if(!root) return;
    remove(root);
}

int bst::s_node(contact *a_contact)
{
    if(!root) return 0;
    s_node(root, a_contact);
    return 0;
}

int bst::p_node(contact *a_contact)
{
    if(!root) return 0;
    p_node(root, a_contact);
    return 0;
}

bool bst::delete_tree(node *&tree)
{
    if(root)
    {
        if(root)
        {
            delete_tree(root->left);
            delete_tree(root->right);
            delete root;
        }
        root = nullptr;
    }
    return true;
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

node *bst::search(node *to_search, contact *a_contact)
{
    return nullptr;
}

node *bst::remove(node *to_remove)
{
    return nullptr;
}

void bst::display_all(node *to_display) const
{

}

node *bst::s_node(node *a_node, contact *a_contact)
{
    while(root->left)
        root = root->left;
    return root;
}

node *bst::p_node(node *a_node, contact *a_contact)
{
    while(root->right)
        root = root->right;
    return root;
}
