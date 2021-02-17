#include "items.hpp"

event::event() : event_name(nullptr), event_time(nullptr)
{
}

event::event(const entry &an_entry) : event_name(arg1), event_time(arg2)
{
}

event::~event()
{
    if (this->event_name)
        delete this->event_name;
    if (this->event_time)
        delete this->event_time;
    this->event_name = this->event_time = nullptr;
}

void event::add(char *param1, char *param2)
{
    this->event_name = new char[strlen(param1) + 1];
    this->event_time = new char[strlen(param2) + 1];
    strcpy(this->event_name, param1);
    strcpy(this->event_time, param2);
}

void event::add(entry &to_add)
{
}

void event::edit(entry &to_edit)
{
}

void event::display() const
{
}

void event::remove()
{
}

void event::remove(entry &to_remove)
{
}

phonecall::phonecall() : phone_name(arg1), phone_number(arg2)
{
}

phonecall::phonecall(const entry &an_entry) : phone_name(arg1), phone_number(arg2)
{
}

phonecall::~phonecall()
{
}

void phonecall::add(char *param1, char *param2)
{
}

void phonecall::add(entry &to_add)
{
}

void phonecall::edit(entry &to_edit)
{
}

void phonecall::display() const
{
}

void phonecall::remove()
{
}

void phonecall::remove(entry &to_remove)
{
}

project::project() : a_project(arg1), due_date(arg2), needed_items(nullptr)
{
}

project::project(const entry &an_entry) : a_project(arg1), due_date(arg2), needed_items(nullptr)
{
}

project::~project()
{
}

void project::add(char *param1, char *param2)
{
}

void project::add(entry &to_add)
{
}

void project::edit(entry &to_edit)
{
}

void project::display() const
{
}

void project::remove()
{
}

void project::remove(entry &to_remove)
{
}

node::node() : items_needed(nullptr), next(nullptr)
{
}

node::node(const node &a_node) : items_needed(a_node.items_needed), next(a_node.next)
{
    if (a_node.items_needed)
    {
        items_needed = new char[strlen(a_node.items_needed) + 1];
        strcpy(items_needed, a_node.items_needed);
        next = a_node.next;
    }
}

node::~node()
{
    if (items_needed)
        delete[] items_needed;
    if (next)
        delete next;
    items_needed = nullptr;
    next = nullptr;
}

void node::add(char *needed)
{
}

void node::remove(node &to_remove)
{
}

void node::set_next(node *is_next)
{
    next = is_next;
}

node &node::get_next()
{
    return *next;
}

void node::display() const
{
}
