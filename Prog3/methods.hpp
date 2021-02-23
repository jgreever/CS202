#include "device.hpp"


class phone : public device
{
    public:
        int add(device *to_add);
        int remove(device &to_remove);
        void display() const;
        int search(device *to_search);

    private:

    protected:
        char *number;
        char *capabilities;
};

class pager : public device
{
    public:
        int add(device *to_add);
        int remove(device &to_remove);
        void display() const;
        int search(device *to_search);

    private:
    
    protected:
        char *number;
        char *capabilities;
};

class voip : public device
{
    public:
        int add(device *to_add);
        int remove(device &to_remove);
        void display() const;
        int search(device *to_search);

    private:

    protected:
        char *number;
        char *capabilities;
};