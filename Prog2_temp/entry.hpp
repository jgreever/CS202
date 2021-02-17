#include <iostream>
#include <cstring>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;

//BASE Class
//Entry class
class entry
{
public:
    entry();
    entry(const entry &an_entry);
    virtual ~entry();

    entry &get_next();
    void set_next(entry *is_next);

    virtual void add(char *param1, char *param2);
    virtual void add(entry &to_add);
    virtual void edit(entry &to_edit);
    virtual void display() const;
    virtual void remove();

private:
protected:
    void remove(entry &to_remove);
    char *arg1;
    char *arg2;
    entry *next;
};