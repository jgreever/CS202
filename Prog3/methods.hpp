#include "device.hpp"


class phone : public device
{
    public:
        phone();
        phone(const phone &to_add);
        ~phone();

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
        pager();
        pager(const pager &to_add);
        ~pager();

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
        voip();
        voip(const voip &to_add);
        ~voip();

        int add(device *to_add);
        int remove(device &to_remove);
        void display() const;
        int search(device *to_search);

    private:

    protected:
        char *number;
        char *capabilities;
};