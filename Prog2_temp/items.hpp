#include "entry.hpp"

//Forward declarations
class node;

class event : public entry
{
public:
    event();
    event(const entry &an_entry);
    ~event();

    //Shared functions
    void add(char *param1, char *param2);
    void add(entry &to_add);
    void edit(entry &to_edit);
    void display() const;
    void remove();

private:
protected:
    void remove(entry &to_remove);
    char *event_name;
    char *event_time;
};

class phonecall : public entry
{
public:
    phonecall();
    phonecall(const entry &an_entry);
    ~phonecall();

    //Shared functions
    void add(char *param1, char *param2);
    void add(entry &to_add);
    void edit(entry &to_edit);
    void display() const;
    void remove();

private:
protected:
    void remove(entry &to_remove);
    char *phone_name;
    char *phone_number;
};

class project : public entry
{
public:
    project();
    project(const entry &an_entry);
    ~project();

    //Shared functions
    void add(char *param1, char *param2);
    void add(entry &to_add);
    void edit(entry &to_edit);
    void display() const;
    void remove();

private:
protected:
    void remove(entry &to_remove);
    char *a_project;
    char *due_date;
    node *needed_items;
};

class node : public project
{
public:
    node();
    node(const node &a_node);
    ~node();

    void add(char *needed);
    void remove(node &to_remove);
    void set_next(node *is_next);
    node &get_next();
    void display() const;

private:
protected:
    char *items_needed;
    node *next;
};