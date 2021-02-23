#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class device
{
    public:
        device();
        device(const device &to_copy);
        virtual ~device();

        void set_next(device *next);
        device *&get_next();

        //Virtual functions
        virtual int add(device *to_add);
        virtual int remove(device &to_remove);
        virtual void display() const;
        virtual int search(device *to_search);
    private:

    protected:
        char *device_type;
        device *next;
};