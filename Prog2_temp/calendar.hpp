#include "day.hpp"

//Calendar class (Holds a 7-day entry as a week)
class calendar
{
public:
    calendar();
    calendar(const calendar &to_copy);
    ~calendar();

    int add(day *&to_add);
    int remove();

private:
protected:
    int remove(day &to_remove);
    day *head;
    day *tail;
};
