#include "day.hpp"

day::day() : next(nullptr), previous(nullptr), head(nullptr)
{
}

day::day(const day &a_day) : next(a_day.next), previous(a_day.previous), head(a_day.head)
{
}

day::~day()
{
    if (next)
        delete next;
    if (previous)
        delete previous;
    if (head)
        delete head;
    next = previous = nullptr;
    head = nullptr;
}

day &day::get_next()
{
    return *next;
}

day &day::get_prev()
{
    return *previous;
}

void day::set_next(day *is_next)
{
    next = is_next;
}

void day::set_prev(day *is_prev)
{
    previous = is_prev;
}

int day::add(entry &to_add)
{
    entry *temp = new entry(to_add);
    day *new_day = new day();
    if (!head)
    {
        entry *head = new entry(to_add);
        head->set_next(nullptr);
        //next->set_next(nullptr);
        //previous->set_prev(nullptr);
    }
    else
    {
        day *current = new_day;
        if (current)
            current = &current->get_next();
        if (!current)
        {
            current->get_prev().set_next(new_day);
            new_day->set_prev(&current->get_prev());
            new_day->set_next(nullptr);
        }
    }
    return 1;
}

int day::remove()
{
    return remove(*this);
}

int day::remove_all()
{
    return 1;
}

void day::display() const
{
}

int day::remove(day &to_remove)
{
    if (to_remove.next)
        delete to_remove.next;
    if (to_remove.previous)
        delete to_remove.previous;
    to_remove.next = to_remove.previous = nullptr;
    if (to_remove.head)
        delete to_remove.head;
    to_remove.head = nullptr;
    return 1;
}

int day::remove_all(calendar &to_remove)
{
    if (head)
        delete head;
    head = nullptr;
    if (next)
        delete next;
    if (previous)
        delete previous;
    next = previous = nullptr;

    return 1;
}
