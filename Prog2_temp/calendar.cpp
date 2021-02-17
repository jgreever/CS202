#include "calendar.hpp"

calendar::calendar() : head(nullptr), tail(nullptr)
{
    //cout << "\nCalendar class constructor called";
}

calendar::calendar(const calendar &to_copy) : head(to_copy.head), tail(to_copy.tail)
{
    //cout << "\nCalendar class object copy constructor called";
}

calendar::~calendar()
{
    //cout << "\nCalendar class destructor called ";
    delete head;
    head = nullptr;
    delete tail;
    tail = nullptr;
}

int calendar::add(day *&to_add)
{
    day *temp = new day(*to_add);
    day *curr = head;
    if (!curr)
    {
        curr = new day(*to_add);
        curr->set_next(tail);
        head = curr;
        return 1;
    }
    else
    {
        tail->get_prev().set_next(temp);
        temp->set_prev(&tail->get_prev());
        temp->set_next(tail);
        return 1;
    }
    return 0;
}

int calendar::remove()
{
    return remove(*head);
}

int calendar::remove(day &to_remove)
{
    day *temp = new day;
    if (head)
    {
        temp = &head->get_next();
        delete head;
        head = temp;
        return 1;
    }
    return 0;
}
