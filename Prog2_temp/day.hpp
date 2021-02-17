#include "items.hpp"

//Forward Declarations
class calendar;

//Day class (DLL)
class day
{
public:
    day();
    day(const day &a_day);
    ~day();
    day &get_next();
    day &get_prev();
    void set_next(day *is_next);
    void set_prev(day *is_prev);
    int add(entry &to_add);
    int remove();
    int remove_all();
    void display() const;

private:
protected:
    int remove(day &to_remove);
    int remove_all(calendar &to_remove);
    day *next;
    day *previous;
    entry *head;
};