#include "entry.hpp"

entry::entry() : next(nullptr)
{
}

entry::entry(const entry &an_entry) : next(an_entry.next)
{
}

entry::~entry()
{
    if (next)
        delete next;
    next = nullptr;
}

entry &entry::get_next()
{
    return *next;
}

void entry::set_next(entry *is_next)
{
    next = is_next;
}

void entry::add(char *param1, char *param2)
{
    arg1 = new char[strlen(param1) + 1];
    arg2 = new char[strlen(param2) + 1];
    strcpy(arg1, param1);
    strcpy(arg2, param2);
}

void entry::add(entry &to_add)
{
    arg1 = new char[strlen(to_add.arg1) + 1];
    arg2 = new char[strlen(to_add.arg2) + 1];
    strcpy(arg1, to_add.arg1);
    strcpy(arg2, to_add.arg2);
}

void entry::edit(entry &to_edit)
{
}

void entry::display() const
{
    cout << "\nArg1: " << arg1;
    cout << "\nArg2: " << arg2;
}

void entry::remove()
{
}

void entry::remove(entry &to_remove)
{
}
